#include <Arduino.h>
#include "Types.h"
#include "Timer.h"
#include "Arrosage.h"

Timer displayMesure = StartTimer(DISPLAY_DELAY);
Arrosage arr = {StartTimer(DUREE_REPOS), false, false};

void interruptRising();
void interruptFalling() {
    Serial.println("interrupt falling");
    arr = startArrosage(arr);
    arr.boutonAppuye = true;
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), interruptRising, RISING);
}

void interruptRising() {
    Serial.println("interrupt rising");
    arr = stopArrosageAndResetTimer(arr);
    arr.boutonAppuye = false;
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), interruptFalling, FALLING);
}

void setup () {
    pinMode (BUTTON_PIN, INPUT);
    pinMode (VALVE_PIN, OUTPUT);
    pinMode (CAPTEUR_DIGITAL_PIN, INPUT);

    digitalWrite (VALVE_PIN, LOW);

    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), interruptFalling, FALLING);

    Serial.begin(115200);
}

void loop () {
    // Envoyer des infos sur le port série
    auto log_status = [=]() {
        if (isTimerPassed(displayMesure)) {
            Serial.println("******");
            Serial.print("Seuil d'arrosage atteint ? : "); Serial.println(digitalRead(CAPTEUR_DIGITAL_PIN));
            Serial.print("Valeur du capteur : "); Serial.println(analogRead(CAPTEUR_ANALOG_PIN));
            Serial.print("En cours ? : "); Serial.println(arr.enCours);
            Serial.print("Dernier changement d'état : "); Serial.println(arr.dureeArrosage.last);
            displayMesure = StartTimer(DISPLAY_DELAY);
            Serial.println("******");
        }
    };

    // On ne lance l'arrosage automatique que si le bouton n'est pas enfoncé
    if (!arr.boutonAppuye)
    {
        // Quand il est temps d'arroser, démarrer l'arrosage
        if (!arr.enCours && isTimerPassed(arr.dureeArrosage) && digitalRead(CAPTEUR_DIGITAL_PIN)) {
            arr.dureeArrosage = StartTimer (DUREE_ARROSAGE);
            arr = startArrosage(arr);
        }

        // Continuer à arroser jusqu'à ce que le Timer soit atteint
        if (arr.enCours && isTimerPassed(arr.dureeArrosage)) {
            arr = stopArrosageAndResetTimer(arr);
        }
    } else {
        log_status();
    }
}
