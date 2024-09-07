#include <util_ess.h>


int setPin(uint8_t pinNum, enum INPUT_TYPES type)
{
    if(pinNum >= 0 && pinNum <= 7)
    {
        if(type == IN)
        {
            CLEAR_BIT(DDRD, pinNum);
            SET_BIT(PORTD, pinNum);
        }
        else
        {
            SET_BIT(DDRD, pinNum);
        }
        return 1;
    }
    else if(pinNum >= 8 && pinNum <= 13)
    {
        uint8_t bitPos = pinNum - 8; // Adjust for PORTB
        if(type == IN)
        {
            CLEAR_BIT(DDRB, bitPos);
            SET_BIT(PORTB, bitPos);
        }
        else
        {
            SET_BIT(DDRB, bitPos);
        }
        return 1;
    }
    else if(pinNum >= 14 && pinNum <= 19)
    {
        uint8_t bitPos = pinNum - 14; // Adjust for PORTC
        if(type == IN)
        {
            CLEAR_BIT(DDRC, bitPos);
            SET_BIT(PORTC, bitPos);
        }
        else
        {
            SET_BIT(DDRC, bitPos);
        }
        return 1;
    }
    else
    {
        return 0;
    }
}


void adc_init()
{
    // Set the reference voltage to AVcc with external capacitor at AREF pin.
    ADMUX = (1 << REFS0); // AVcc with external capacitor

    // Set the prescaler to 128
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // ADEN (ADC Enable) and ADPS (ADC Prescaler)
}

uint16_t adc_read(const uint8_t pin)
{
    uint8_t truePin = pin - 14u;
    ADMUX = (ADMUX & 0xF0) | (truePin & 0x0F); // clear lower 4 bits of ADMUX and set the lower 4 bits to be the pin channel A0-A5.
    ADCSRA |= (1 << ADSC); // set bit ADSC to start conversion.

    while(ADCSRA & (1 << ADSC)); // wait for the conversion to end.
    return ADC;
}

bool digitalCheck(const uint8_t pin)
{
    if(pin >= 0 && pin <= 7)
    {
        //check if bit is high -> button pressed
        if(PIND & (1 << pin))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if(pin >= 8 && pin <= 13)
    {
        //check if bit is high -> button pressed
        if(PINB & (1<< (pin-8u)))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}