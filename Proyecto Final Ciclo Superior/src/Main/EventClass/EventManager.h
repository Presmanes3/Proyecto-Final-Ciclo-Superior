#ifndef _EVENT_MANAGER_H_
#define _EVENT_MANAGER_H_

#include "Arduino.h"

class Timer;
class TimeManager;

/* Manages Event which have a Time Manager and two timers in order to control what happens with the timers*/
class EventManager
{
public:
  EventManager(TimeManager *timeManager, Timer *checkTimer,
               Timer *standByTimer);

protected:
  TimeManager *timeManager;
  Timer *checkTimer;
  Timer *standByTimer;
};
#endif
