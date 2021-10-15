#ifndef TIMER_H
#define TIMER_H

namespace Timer {
    struct Timer {
        unsigned int duration;
        unsigned int last;
    };

    Timer create (unsigned int duration);
    bool isPassed (Timer t);
}

#endif