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
 * const char key_map[4][4] = {
 *   { '0', '1', '2', '3' },
 *   { '4', '5', '6', '6' },
 *   { '7', '8', '9', 'A' },
 *   { 'B', 'C', 'D', 'E' }
 * };
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

#include <stdint.h>

#define MAX_GPIOS 4

/* Port identifiers */
enum port {
    INPUT_PORT,     /* Columns  */
    OUTPUT_PORT     /* Rows     */
};

/* Hardware abstraction functions (to be implemented per MCU) */
void set_gpio(enum port p, uint8_t pin, uint8_t value);
uint8_t gpio_read(enum port p, uint8_t pin);
void delay_us(uint16_t us);

/**
 * scan_keypad()
 * 
 * Scans a 4x4 matrix keypad.
 * Returns:
 *   16-bit value where each bit represents a key.
 *   Bit position = row * 4 + column
 *
 * Example:
 *   Row 2, Column 1 → bit (2*4+1) = bit 9
 */
uint16_t scan_keypad(void)
{
    uint8_t row, col;
    uint16_t key_state = 0;

    /* Loop through each row */
    for (row = 0; row < MAX_GPIOS; row++)
    {
        /* Step 1: Set all rows HIGH (inactive) */
        for (uint8_t r = 0; r < MAX_GPIOS; r++)
            set_gpio(OUTPUT_PORT, r, 1);

        /* Step 2: Drive current row LOW (active row) */
        set_gpio(OUTPUT_PORT, row, 0);

        /* Small delay to allow signals to settle */
        delay_us(5);

        /* Step 3: Read all column inputs */
        for (col = 0; col < MAX_GPIOS; col++) {
            /* Active LOW: if column reads 0, key is pressed */
            if (gpio_read(INPUT_PORT, col) == 0) {
                /* Set corresponding bit in key_state */
                key_state |= (1 << (row * MAX_GPIOS + col));
            }
        }
    }

    return key_state;
}
