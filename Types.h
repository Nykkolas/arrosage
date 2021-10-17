#ifndef TYPES_H
#define TYPES_H

#include <Arduino.h>

// Consts
// Configuration de l'Arduino
const unsigned int BUTTON_PIN = 2;
const unsigned int VALVE_PIN = 9;
const unsigned int CAPTEUR_DIGITAL_PIN = A0;
const unsigned int CAPTEUR_ANALOG_PIN = A1;

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
    Timer dureeArrosage; // Durée d'arrosage et durée sans arrosage après avoir arrosé
    bool enCours;
    bool boutonAppuye; // Pour éviter de tester BUTTON_PIN à chaque loop. Changé lors des interruptions
};

#endif