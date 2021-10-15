#ifndef TYPES_H
#define TYPES_H

#include <Arduino.h>

// Consts
// Configuration de l'Arduino
const unsigned int BUTTON_PIN = 2;
const unsigned int VALVE_PIN = 9;
const unsigned int CAPTEUR_PIN = A0;

// Configuration des délais pour le Timer
const unsigned long DISPLAY_DELAY = 1000;
const unsigned long DUREE_ARROSAGE = 5000;
const unsigned long DUREE_REPOS = 10000;

// Types
struct Timer {
    unsigned long duration;
    unsigned long last;
};

struct Arrosage {
    Timer dureeArrosage;
    bool enCours;
};

#endif