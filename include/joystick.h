#pragma once
#include "util_ess.h"

 

/// @brief class to represent a joystick
class Jstick 
{
    private:
        uint8_t vrxPin; // pin number of the vrx.
        uint8_t vryPin; // pin number of the vry.
        uint8_t swPin; // pin number the joystick push button.
        bool valid;

        bool test_correct_pins(const uint8_t vrxPin, const uint8_t vryPin,const uint8_t swPin);
    public:
        /// @brief construct a joy stick object.
        /// @param vrxPin x axis pins->A0j,A1j,A2j,A3j,A4j,A5j
        /// @param vryPin y axis pins->A0j,A1j,A2j,A3j,A4j,A5j
        /// @param swPin push btn pins->0-13
        Jstick(const uint8_t vrxPin, const uint8_t vryPin, const uint8_t swPin);

        /// @brief check if jstick acttualy constructed -> cause there aren't exceptions
        /// @return true if constructed.
        bool is_Constructed() const;

        // return the x axis value 0-1023.
        uint16_t get_current_xAxis() const;

        // return the y axis value 0-1023.
        uint16_t get_current_yAxis() const;

        // return true if button pressed.
        bool get_pBtn_pressed() const;

        // getters for the pin numbers.
        uint8_t get_vrxPin() const;
        uint8_t get_vryPin() const;
        uint8_t get_btnPin() const;
};