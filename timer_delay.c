/**
 * @file timer_delay.c
 * @brief Build delay_ms() using timer registers.
 * Target: ATmega328P (Arduino Uno)
 */

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_ms_timer0(uint16_t ms) {
    // Configure Timer0: CTC mode, 64 prescaler
    TCCR0A = (1 << WGM01);
    TCCR0B = (1 << CS01) | (1 << CS00);
    
    // 1ms at 16MHz with 64 prescaler:
    // (16,000,000 / 64) * 0.001 = 250
    OCR0A = 249; 

    for (uint16_t i = 0; i < ms; i++) {
        TCNT0 = 0;
        TIFR0 |= (1 << OCF0A); // Clear flag
        while (!(TIFR0 & (1 << OCF0A))); // Wait for 1ms
    }
    
    TCCR0B = 0; // Stop timer
}

int main(void) {
    DDRB |= (1 << PB5);

    while (1) {
        PORTB ^= (1 << PB5);
        delay_ms_timer0(1000); // 1 second delay
    }

    return 0;
}
