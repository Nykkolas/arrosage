#include <Arduino.h>
#include "Types.h"
#include "Timer.h"

Timer displayMesure = StartTimer(DISPLAY_DELAY);

Arrosage arr = {StartTimer(DUREE_REPOS), false};

void setup () {
    pinMode (BUTTON_PIN, INPUT);
    pinMode (VALVE_PIN, OUTPUT);
    pinMode (CAPTEUR_PIN, INPUT);

    digitalWrite (VALVE_PIN, LOW);

    Serial.begin(115200);
}

void loop () {
    // Quand il est temps d'arroser, démarrer l'arrosage
    if (!arr.enCours && digitalRead(CAPTEUR_PIN) && isTimerPassed(arr.dureeArrosage)) {
        digitalWrite(VALVE_PIN, HIGH);
        arr.dureeArrosage = StartTimer (DUREE_ARROSAGE);
        arr.enCours = true;
    }

    // Continuer à arroser jusqu'à ce que le Timer soit atteint
    if (arr.enCours && isTimerPassed(arr.dureeArrosage)) {
        digitalWrite(VALVE_PIN, LOW);
        arr.dureeArrosage = StartTimer(DUREE_REPOS);
        arr.enCours = false;
    }

    // Quand on appuie sur le bouton
    if (!digitalRead(BUTTON_PIN))
    {
        if (isTimerPassed(displayMesure)) {
            Serial.print("Valeur du capteur : "); Serial.println(digitalRead(CAPTEUR_PIN));
            Serial.print("En cours ? : "); Serial.println(arr.enCours);
            Serial.print("Dernier changement d'état : "); Serial.println(arr.dureeArrosage.last);
            displayMesure = StartTimer(DISPLAY_DELAY);
        }
    }
}
