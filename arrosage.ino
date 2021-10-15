#include <Arduino.h>
#include "conf.h"
#include "Timer.h"

Timer::Timer displayMesure = Timer::create(DISPLAY_DELAY);

void setup () {
    pinMode (BUTTON_PIN, INPUT);
    pinMode (VALVE_PIN, OUTPUT);
    pinMode (CAPTEUR_PIN, INPUT);

    digitalWrite (VALVE_PIN, LOW);

    Serial.begin(115200);
}

void loop () {
    switch (digitalRead(BUTTON_PIN))
    {
    case LOW:
        digitalWrite(VALVE_PIN, HIGH);
        if (Timer::isPassed(displayMesure)) {
            Serial.println(analogRead(CAPTEUR_PIN));
            displayMesure = Timer::create(DISPLAY_DELAY);
        }
        break;
    
    default:
        digitalWrite(VALVE_PIN, LOW);
        break;
    }
}