/**
 * @file led_blink_timer.c
 * @brief LED blink using hardware timer (polling method).
 * Target: ATmega328P (Arduino Uno)
 */

#define F_CPU 16000000UL
#include <avr/io.h>

#define LED_PIN PB5

void timer1_delay_500ms() {
    // Set Timer1 to Normal mode, no prescaler initially
    TCCR1A = 0;
    TCCR1B = 0;
    
    // For 500ms at 16MHz with 256 prescaler:
    // Target = (16,000,000 / 256) * 0.5 = 31250
    TCNT1 = 65536 - 31250;
    
    // Start timer with 256 prescaler
    TCCR1B |= (1 << CS12);
    
    // Wait for overflow flag
    while (!(TIFR1 & (1 << TOV1)));
    
    // Stop timer and clear flag
    TCCR1B = 0;
    TIFR1 |= (1 << TOV1);
}

int main(void) {
    DDRB |= (1 << LED_PIN);

    while (1) {
        PORTB ^= (1 << LED_PIN);
        timer1_delay_500ms();
    }

    return 0;
}
