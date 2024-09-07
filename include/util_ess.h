#pragma once
#include <avr/io.h>

#define A0j 14u
#define A1j 15u
#define A2j 16u
#define A3j 17u
#define A4j 18u
#define A5j 19u

#define SET_BIT(reg, bit) (reg |= (1 << bit))
#define CLEAR_BIT(reg, bit) (reg &= ~(1 << bit))

enum INPUT_TYPES
{
    IN = 0,
    OUT = 1
}; 

/// @brief sets pin to a input/output state.
/// @param pinNum number of pin to set.
/// @param type in/out
/// @return response code.
int setPin(uint8_t pinNum,enum INPUT_TYPES type);

// initialize adc to 128 prescalar.
void adc_init();

/// @brief reads from analog pin.
/// @param pin analog pin number.
/// @return value.
uint16_t adc_read(const uint8_t pin);

/// @brief check if bit is set to high or low.
/// @param pin digital pin number.
/// @return true/false -> high/low.
bool digitalCheck(const uint8_t pin);
