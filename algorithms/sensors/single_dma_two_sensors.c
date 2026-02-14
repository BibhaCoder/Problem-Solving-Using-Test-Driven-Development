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
 * 1) DMA thread: Highest priority DMA threads which moves data written by sensors to 2 separate rings buffers
 * 2) RT thread: High priority threads which processes real time sensor
 * 3) Non-RT thread: Low priority thread which processes non real time sensor on best effort basis.
 *
 * Only 1 interrupt from both thr sensors to avoid interrupt strom.
 * All 3 threads are bottom halves.
 * Highest priority DMA thread is the only caller of non-thread safe DMA API and copies sensors data to their respective ring buffers and schedule both RT and non-RT thread to run.
 * RT thread processes RT ring buffers and meets scheduling KPIs.
 * Non RT thread does best effort processing of non RT ring buffers.
 *
 */
