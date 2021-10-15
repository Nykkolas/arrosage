#include "Timer.h"
#include <Arduino.h>

Timer createTimer (unsigned int duration) {
    Timer t = {duration, millis()};

    return  t;
}

bool isTimerPassed (Timer t) {
    bool r = millis() - t.last > t.duration;

    return r;
}

