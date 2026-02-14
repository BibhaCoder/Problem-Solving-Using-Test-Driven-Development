/**
 * 1 single DMA non thread safe API
 * 2 sensors:
 * 1) One real-time sensors which has hard real time scheduling requirements (less than 5 ms)
 * 2) Second non real-time sensor which does not real time scheduling constraints but generates 5 times mote data
 *
 */

/**
 * Design options:
 * 3 threads:
 * 1) DMA thread (Serializer): Highest priority DMA threads which moves data written by sensors to 2 separate rings buffers
 * 2) RT thread: High priority threads which processes real time sensor
 * 3) Non-RT thread: Low priority thread which processes non real time sensor on best effort basis.
 *
 * Only 1 interrupt from both the sensors to avoid interrupt strom.
 * All 3 threads are bottom halves.
 * Highest priority DMA thread is the only caller of non-thread safe DMA API and copies sensors data to their respective ring buffers and schedule both RT and non-RT thread to run.
 * RT thread processes RT ring buffers and meets scheduling KPIs.
 * Non RT thread does best effort processing of non RT ring buffers.
 *
 *
 * System Architecture Overview
 * ​The flow utilizes a "Producer-Consumer" pattern where the DMA thread acts as the sole producer for two independent consumers.
 * ​1. The DMA Thread (The Serializer)
 * ​Role: Acts as the gatekeeper for the non-thread-safe API.
​ * Priority: Highest. It must preempt everything to ensure the DMA hardware is never idle and the interrupt is serviced immediately.
​ * Efficiency: This thread should do zero data processing. Its only job is:
 * ​Read hardware registers/buffers.
 * ​Dispatch data to the correct Ring Buffer (RT or Non-RT).
​ * Trigger the consumer threads.
​ * 2. The Ring Buffers (The Decouplers)
 * ​RT Ring Buffer: Should be sized to handle worst-case jitter. Since the requirement is < 5 ms, the buffer only needs to hold a few samples, but it must be lock-free (SPSC - Single Producer Single Consumer) to avoid blocking the DMA thread.
 * ​Non-RT Ring Buffer: Needs to be significantly larger (5x data volume). Since this is "best effort," this buffer acts as a pressure valve. If the Non-RT thread falls behind, the buffer will fill; you must decide if you will drop old data or overwrite it.
 * ​Critical Challenges & Refinements
 * ​The "Interrupt Storm" Mitigation
 * ​You mentioned using a single interrupt. This is smart, but it implies a Status Register check.
​ * Check: Ensure the DMA thread clears the interrupt source immediately upon entry. If the Non-RT sensor is firing 5x more often, the DMA thread will be woken up frequently. You must ensure the overhead of waking the DMA thread 5x for the Non-RT sensor doesn't starve the RT thread's processing time.
 * ​Potential Bottleneck: DMA Transfer Time
 * ​Since the DMA API is non-thread-safe and single-channel (implied), the RT data might get stuck behind a large Non-RT data transfer.
 ​* Optimization: If the DMA API supports burst sizes, keep the Non-RT bursts small. You don't want the DMA hardware busy moving a massive Non-RT block when an RT sample arrives.
 * ​Priority Inversion Risk
 * ​Even with a lock-free design, if the Non-RT thread (low priority) holds a system-wide resource (like a memory bus or a mutex for logging) that the RT thread needs, you'll miss your 5 ms window.
 * ​Advice: Keep the RT thread entirely self-contained.
 *
 * ​Comparison of Design Elements
 * a) Feature: RT Sensor vs Non-RT Sensor
 * b) Priority: High (Immediate) vs Low (Best Effort)
 * c) Data Volume: 1x vs 5x
 * d) Latency Goal: < 5 ms vs N/A
 * e) Ring buffer Strategy:  Small, Fixed-Latency Large vs Overflow-tolerant
 */

/**
 * Why the 3-Thread Design is optimal for both single core and multi core
 * ​1. Determinism vs. Blocking
​ * In a 2-thread + Mutex model, if the Low-Priority (Non-RT) thread is currently calling the DMA API to move its large (5x) data chunk, it will hold the mutex. If the RT sensor fires during this time, the High-Priority RT thread will be blocked waiting for the mutex.
​ * Even though the RT thread is higher priority, it is now "at the mercy" of how long the Non-RT thread takes to finish its DMA call. This makes your 5 ms deadline unpredictable.
 * ​2. The "Serializer" Advantage
​ * In your 3-thread design, the DMA Thread acts as a Hardware Proxy.
 * ​The RT and Non-RT threads never compete for the DMA API.
 * ​They only interact with their respective Ring Buffers.
 * ​Since the DMA thread is the highest priority, it can preempt the Non-RT thread instantly to service the RT sensor.*
 *
 * ​Stick with the 3-thread design. It is a professional-grade architecture for mixed-criticality systems. It keeps your real-time logic isolated from the "heavy lifting" of the non-real-time data.
 *
 */
