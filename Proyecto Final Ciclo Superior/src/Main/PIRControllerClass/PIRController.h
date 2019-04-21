#ifndef _PIR_CONTROLLER_H
#define _PIR_CONTROLLER_H

#include "../Common.h"
#include "Arduino.h"

class PIRController : public EventManager, public AbstractSensor {

public:
  PIRController(TimeManager *timeManager, Timer *checkTimer,
                Timer *standByTimer);

  void run(bool debug = false);
  void setup(bool debug = false) override;
  bool read(bool debug = false) override;

  void turnOnLight(bool debug = false);
  void turnOffLight(bool debug = false);
};

#endif
