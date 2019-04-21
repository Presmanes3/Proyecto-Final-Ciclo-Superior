#ifndef _LDR_CONTROLLER_H
#define _LDR_CONTROLLER_H

#include "../Common.h"
#include "Arduino.h"

class LDRController : public EventManager, public AbstractSensor {

public:
  LDRController(TimeManager *timeManager, Timer *checkTimer,
                Timer *standByTimer);

  void run(bool debuf = false);
  void setup(bool debug = false) override;
  bool read(bool debug = false) override;

  void turnOnLight(bool debug = false);
  void turnOffLight(bool debug = false);

  void setThreshold(uint16_t newVal);
  uint16_t getThreshold();

private:
  uint16_t threshold;
};

#endif
