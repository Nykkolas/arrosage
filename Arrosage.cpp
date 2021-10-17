#include <Arduino.h>
#include "Arrosage.h"
#include "Timer.h"

// Démarrer l'arrosage et lancer le timer
Arrosage startArrosage(Arrosage arr) {
    digitalWrite(VALVE_PIN, HIGH);
    arr.dureeArrosage = StartTimer (DUREE_ARROSAGE);
    arr.enCours = true;

    return arr;
};

// Arrêter l'arrosage et relancer le timer de repos
Arrosage stopArrosage(Arrosage arr) {
    digitalWrite(VALVE_PIN, LOW);
    arr.dureeArrosage = StartTimer(DUREE_REPOS);
    arr.enCours = false;

    return arr;
};
