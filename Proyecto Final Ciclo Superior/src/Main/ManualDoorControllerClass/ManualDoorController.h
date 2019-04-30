#ifndef _MANUAL_DOOR_CONTROLLER_H
#define _MANUAL_DOOR_CONTROLLER_H

#include "../CapacityManagerClass/Capacity.h"
#include "../Common.h"
#include "Arduino.h"

class ManualDoorController : public EventManager, public AbstractSensor {
public:
  ManualDoorController(CapacityManager *capacityManager,
                       TimeManager *timeManager, Timer *checkTimer,
                       Timer *standByTimer);

  bool button_option;
  bool read_flag;

  /* Update function called at main loop*/
  void run();

  /* Starts the sensor*/
  void setup() override;

  /* Read the sensor*/
  bool read() override;

  /* Turns on light configured on setup*/
  void turnOnLight();

  /* Turns off light configured on setup*/
  void turnOffLight();

  /*Return which button has been pressed*/
  bool getButtonOption();

private:
  CapacityManager *capacityManager;
};
#endif
