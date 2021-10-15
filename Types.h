#ifndef TYPES_H
#define TYPES_H

// Consts
const unsigned int BUTTON_PIN = 2;
const unsigned int VALVE_PIN = 9;
const unsigned int CAPTEUR_PIN = A0;

const unsigned int DISPLAY_DELAY = 1000;

// Types
struct Timer {
    unsigned int duration;
    unsigned int last;
};

#endif