#ifndef _TIME_MANAGER_H_
#define _TIME_MANAGER_H_

#include "Arduino.h"
#include "Timer.h"

/*Class for manage time through Timer objects*/
class TimeManager
{
public:
  /* Compares Timer reference to Timer time to past in milliseconds*/
  bool pastMil(Timer &timer);

  /* Compares Timer reference to Timer time to past in Seconds*/
  bool pastSec(Timer &timer);

  /* Compares Timer reference to Timer time to past in Minutes*/
  bool pastMin(Timer &timer);
};
#endif
