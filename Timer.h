#ifndef TIMER_H
#define TIMER_H

#include "Types.h"

Timer StartTimer (unsigned int duration);
bool isTimerPassed (Timer t);

#endif