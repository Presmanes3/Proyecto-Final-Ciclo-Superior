#ifndef _EMERGENCY_DOOR_H_
#define _EMERGENCY_DOOR_H_

#include "../Common.h"
#include "Arduino.h"
//#include "EmerDoorFSM.h"

class EmerDoorController : public EventManager, public AbstractSensor {

public:
  EmerDoorController(TimeManager *timeManager, Timer *checkTimer,
                     Timer *standByTimer);

  bool read(bool debug = false) override;
  void setup(bool debug = false) override;
  void run(bool debug = false);

  void turnOnLight(bool debug = false);
  void turnOffLight(bool debug = false);
};

#endif
