#ifndef _EMERGENCY_DOOR_H_
#define _EMERGENCY_DOOR_H_

#include "../Common.h"
#include "Arduino.h"
//#include "EmerDoorFSM.h"

class EmerDoorController : public EventManager, public AbstractSensor {

public:
  EmerDoorController(TimeManager *timeManager, Timer *checkTimer,
                     Timer *standByTimer);

  /* Reads the sensor and return a bool*/
  bool read() override;

  /* Starts the sensor*/
  void setup() override;

  /* Update function called at main loop*/
  void run();

  /* Turns on light configured at setup*/
  void turnOnLight();

  /* Turns off light configured at setup*/
  void turnOffLight();
};

#endif
