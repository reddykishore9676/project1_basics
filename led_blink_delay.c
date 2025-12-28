/**
 * @file led_blink_delay.c
 * @brief LED blink using software delay.
 * Target: ATmega328P (Arduino Uno)
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB5 // Digital Pin 13 on Arduino Uno

int main(void) {
    // Set LED_PIN as output
    DDRB |= (1 << LED_PIN);

    while (1) {
        // Toggle LED
        PORTB ^= (1 << LED_PIN);
        // Software delay
        _delay_ms(500);
    }

    return 0;
}
