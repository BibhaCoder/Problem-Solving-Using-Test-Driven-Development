/*
 * A 4×4 matrix keyboard (keypad) scan with 2 ports, each having 4 GPIO pins, is a standard way to read 16 keys using only 8 microcontroller pins.
 * 🔷 Hardware Configuration
 * Divide the keypad into:
 * 4 Rows → Connected to Port A (4 GPIOs)
 * 4 Columns → Connected to Port B (4 GPIOs)
 * Example:
 * Keypad Line
 * MCU Connection
 * Row 0
 * PortA.0
 * Row 1
 * PortA.1
 * Row 2
 * PortA.2
 * Row 3
 * PortA.3
 * Col 0
 * PortB.0
 * Col 1
 * PortB.1
 * Col 2
 * PortB.2
 * Col 3
 * PortB.3
 * 🔷 Basic Working Principle
 * Rows → Outputs
 * Columns → Inputs with pull-up resistors
 * Only one row is driven LOW at a time. Columns are read to see if any key in that row is pressed.
 * When a key is pressed:
 * It connects the active row to a column.
 * That column input becomes LOW.
 * The row & column number identifies the key.
 * 🔷 Scanning Algorithm (Step-by-Step)
 * 1️⃣ Initialization
 * Text
 * Copy code
 * PortA (Rows)  → Output
 * PortB (Cols)  → Input with Pull-ups enabled
 * 2️⃣ Scan Process
 * For each row:
 * Set all rows HIGH
 * Drive one row LOW
 * Read column inputs
 * If any column reads LOW → Key detected
 * Move to next row
 * 🔷 Example Scan Logic (Pseudo Code)
 * C
 * Copy code
 * for(row = 0; row < 4; row++)
 * { 
 *   Set all rows HIGH
 *   Set current row LOW
 *   
 *   delay_us(5);   // small settle time
 *   
 *   col = Read columns
 *   
 *  if(col != 0x0F)   // if any column LOW
 *   {
 *      determine which column is LOW
 *       key = lookup_table[row][col]
 *   }
 *}
 * 🔷 Key Mapping Example
 *
 * C0
 * C1
 * C2
 * C3
 * R0
 * 1
 * 2
 * 3
 * A
 * R1
 * 4
 * 5
 * 6
 * B
 * R2
 * 7
 * 8
 * 9
 * C
 * R3
 * *
 * 0
 * #
 * D
 * 🔷 Important Design Notes
 * ✅ Debouncing
 * Mechanical keys bounce for ~5–20 ms. Add:
 * Software delay (~10–20 ms), OR
 * State confirmation (read twice)
 * ✅ Ghosting Problem
 * If multiple keys are pressed simultaneously, false detection may occur. Solution:
 * Add diodes in series with each key (for true N-key rollover)
 * ✅ Scan Speed
 * Typical scan loop:
 * Every 5–20 ms
 * 🔷 Electrical Summary
 * Total GPIO used: 8
 * Rows → Output push-pull
 * Columns → Input pull-up
 * Idle state → All columns HIGH
 * Pressed key → Column LOW
 *
 * uint16_t data style is good enough to store all 16 inputs
*/
