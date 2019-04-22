#ifndef _PIR_CONTROLLER_H
#define _PIR_CONTROLLER_H

#include "../Common.h"
#include "Arduino.h"

class PIRController : public EventManager, public AbstractSensor {

public:
  PIRController(TimeManager *timeManager, Timer *checkTimer,
                Timer *standByTimer);

  void run();
  void setup() override;
  bool read() override;

  void turnOnLight();
  void turnOffLight();
};

#endif
