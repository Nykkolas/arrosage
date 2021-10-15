#include "Timer.h"
#include <Arduino.h>

Timer StartTimer (unsigned long duration) {
    Timer t = {duration, millis()};

    return  t;
}

bool isTimerPassed (Timer t) {
    bool r = millis() - t.last > t.duration;

    return r;
}

