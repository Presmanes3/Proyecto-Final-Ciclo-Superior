#ifndef _EMERGENCY_DOOR_H_
#define _EMERGENCY_DOOR_H_

#include "../Common.h"
#include "Arduino.h"
//#include "EmerDoorFSM.h"

class EmerDoorController : public EventManager, public AbstractSensor {

public:
  EmerDoorController(TimeManager *timeManager, Timer *checkTimer,
                     Timer *standByTimer);

  bool read() override;
  void setup() override;
  void run();

  void turnOnLight();
  void turnOffLight();
};

#endif
