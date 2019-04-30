#ifndef _LDR_CONTROLLER_H
#define _LDR_CONTROLLER_H

#include "../Common.h"
#include "Arduino.h"

class LDRController : public EventManager, public AbstractSensor {

public:
  LDRController(TimeManager *timeManager, Timer *checkTimer,
                Timer *standByTimer);

  /* Update function called at main loop*/
  void run();

  /* Starts the sensor*/
  void setup() override;

  /* Reads the sensor and return a bool*/
  bool read() override;

  /* Turn on a light configured on setup*/
  void turnOnLight();

  /* Turn off a light configured on setup*/
  void turnOffLight();

  /* Set a threshold fo trigger the sensor*/
  void setThreshold(uint16_t newVal);

  /* Returns threshold value*/
  uint16_t getThreshold();

private:

  /* Threshold to trigguer the read function*/
  uint16_t threshold;
};

#endif
