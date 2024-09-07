#include "joystick.h"


Jstick::Jstick(const uint8_t vrxPin, const uint8_t vryPin, const uint8_t swPin)
{
    this->valid = test_correct_pins(vrxPin, vryPin, swPin);
    if(this->valid)
    {
        adc_init();

        //tests if pins set worked.
        if(setPin(vrxPin, IN) == 0){
            this->valid = false;
        }
        if(setPin(vryPin, IN) == 0){
            this->valid = false;
        }
        if(setPin(swPin, IN) == 0){
            this->valid = false;
        }

        this->vrxPin = vrxPin;
        this->vryPin = vryPin;
        this->swPin = swPin;
    }
}

bool Jstick::test_correct_pins(const uint8_t vrxPin, const uint8_t vryPin,const uint8_t swPin)
{
    if(vrxPin == vryPin || vrxPin == swPin || vryPin == swPin)
    {
        return false; 
    }

    if(vrxPin < A0j || vrxPin > A5j)
    {
        return false;
    }

    if(vryPin < A0j || vryPin > A5j)
    {
        return false;
    }

    if(swPin < 0 || swPin > 13)
    {
        return false;
    }

    return true;
}

bool Jstick::is_Constructed() const
{
    return this->valid;
}

uint16_t Jstick::get_current_xAxis() const
{
    return adc_read(this->vrxPin);
}

uint16_t Jstick::get_current_yAxis() const
{
    return adc_read(this->vryPin);
}

uint8_t Jstick::get_vryPin() const
{
    return this->vryPin;
}

uint8_t Jstick::get_vrxPin() const
{
    return this->vrxPin;
}

uint8_t Jstick::get_btnPin() const
{
    return this->swPin;
}

bool Jstick::get_pBtn_pressed() const
{
    return digitalCheck(this->swPin);
}