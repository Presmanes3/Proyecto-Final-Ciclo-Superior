#ifndef _EVENT_MANAGER_H_
#define _EVENT_MANAGER_H_

#include "Arduino.h"

class Timer;
class TimeManager;

class EventManager {
public:
  EventManager(TimeManager *timeManager, Timer *checkTimer,
               Timer *standByTimer);

protected:
  TimeManager *timeManager;
  Timer *checkTimer;
  Timer *standByTimer;
};
#endif
