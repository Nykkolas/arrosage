#include <Arduino.h>
#include "Arrosage.h"
#include "Timer.h"

// Démarrer l'arrosage SANS lancer le timer de durée d'arrosage
Arrosage startArrosage(Arrosage arr) {
    digitalWrite(VALVE_PIN, HIGH);
    arr.enCours = true;

    return arr;
};

// Arrêter l'arrosage et relancer le timer de repos
Arrosage stopArrosageAndResetTimer(Arrosage arr) {
    digitalWrite(VALVE_PIN, LOW);
    arr.dureeArrosage = StartTimer(DUREE_REPOS);
    arr.enCours = false;

    return arr;
};
