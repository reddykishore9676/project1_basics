/**
 * @file button_input_read.c
 * @brief Read button input and display state on LED.
 * Target: ATmega328P (Arduino Uno)
 */

#define F_CPU 16000000UL
#include <avr/io.h>

#define LED_PIN PB5    // Digital Pin 13
#define BUTTON_PIN PD2 // Digital Pin 2

int main(void) {
    // Set LED as output
    DDRB |= (1 << LED_PIN);
    
    // Set Button as input
    DDRD &= ~(1 << BUTTON_PIN);
    // Enable internal pull-up resistor
    PORTD |= (1 << BUTTON_PIN);

    while (1) {
        // Read button (Active Low due to pull-up)
        if (!(PIND & (1 << BUTTON_PIN))) {
            PORTB |= (1 << LED_PIN);  // Turn LED ON
        } else {
            PORTB &= ~(1 << LED_PIN); // Turn LED OFF
        }
    }

    return 0;
}
