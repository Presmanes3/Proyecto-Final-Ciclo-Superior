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

  void run();
  void setup() override;
  bool read() override;

  void turnOnLight();
  void turnOffLight();

  bool getButtonOption();

private:
  CapacityManager *capacityManager;
};
#endif
