#ifndef _TIME_MANAGER_H_
#define _TIME_MANAGER_H_

#include "Arduino.h"
#include "Timer.h"

class TimeManager
{

public:
  bool pastMil(Timer &timer);
  bool pastSec(Timer &timer);
  bool pastMin(Timer &timer);
};
#endif
