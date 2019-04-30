#ifndef _PIR_CONTROLLER_H
#define _PIR_CONTROLLER_H

#include "../Common.h"
#include "Arduino.h"

class PIRController : public EventManager, public AbstractSensor {

public:
  PIRController(TimeManager *timeManager, Timer *checkTimer,
                Timer *standByTimer);

  /* Update function called at main loop*/
  void run();

  /* Starts the sensor*/
  void setup() override;

  /* Reads the sensor and returns a bool*/
  bool read() override;

  /* Turn on light configured on setup*/
  void turnOnLight();

  /* Turn off light configured on setup*/
  void turnOffLight();
};

#endif
