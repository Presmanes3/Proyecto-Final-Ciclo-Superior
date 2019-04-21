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

  void run(bool debug = false);
  void setup(bool debug = false) override;
  bool read(bool debug = false) override;

  void turnOnLight(bool debug = false);
  void turnOffLight(bool debug = false);

  bool getButtonOption(bool debug = false);

private:
  CapacityManager *capacityManager;
};
#endif
