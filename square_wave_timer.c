/**
 * @file square_wave_timer.c
 * @brief Generate 1Hz/2Hz/5Hz square waves using Timer1 CTC mode.
 * Target: ATmega328P (Arduino Uno)
 */

#define F_CPU 16000000UL
#include <avr/io.h>

#define OUTPUT_PIN PB1 // OC1A (Digital Pin 9)

void setup_timer1_ctc(uint16_t compare_value) {
    // Set PB1 as output
    DDRB |= (1 << OUTPUT_PIN);
    
    // Configure Timer1 for CTC mode
    TCCR1A = (1 << COM1A0); // Toggle OC1A on compare match
    TCCR1B = (1 << WGM12) | (1 << CS12); // CTC mode, 256 prescaler
    
    OCR1A = compare_value;
}

int main(void) {
    /**
     * Calculation for OCR1A:
     * F_out = F_CPU / (2 * Prescaler * (1 + OCR1A))
     * OCR1A = (F_CPU / (2 * Prescaler * F_out)) - 1
     * 
     * For 1Hz: OCR1A = (16,000,000 / (2 * 256 * 1)) - 1 = 31249
     * For 2Hz: OCR1A = (16,000,000 / (2 * 256 * 2)) - 1 = 15624
     * For 5Hz: OCR1A = (16,000,000 / (2 * 256 * 5)) - 1 = 6249
     */
    
    setup_timer1_ctc(31249); // Default to 1Hz

    while (1) {
        // Main loop
    }

    return 0;
}
