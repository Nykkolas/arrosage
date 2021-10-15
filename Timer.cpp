#include "Timer.h"
#include <Arduino.h>

namespace Timer {
    Timer create (unsigned int duration) {
        Timer t = {duration, millis()};

        return  t;
    }

    bool isPassed (Timer t) {
        bool r = millis() - t.last > t.duration;

        return r;
    }
}
