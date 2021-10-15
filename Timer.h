#ifndef TIMER_H
#define TIMER_H

#include "Types.h"

Timer StartTimer (unsigned long duration);
bool isTimerPassed (Timer t);

#endif