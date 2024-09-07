#include "joystick.h"
#include <Arduino.h>

Jstick stick(A0j,A1j,7);

void setup() 
{
    Serial.begin(9600);
    if(stick.is_Constructed())
    {
        Serial.println("valid");
    }
    else
    {
        Serial.println("not valid");
    }
}

void loop() 
{
    delay(200);

    // Check if the joystick is constructed and print axis values
    if (stick.is_Constructed())
    {
        Serial.print("x: ");
        Serial.println(stick.get_current_xAxis());
        Serial.print("y: ");
        Serial.println(stick.get_current_yAxis());
        Serial.print("Pressed: ");
        Serial.println(stick.get_pBtn_pressed());
    }
}

