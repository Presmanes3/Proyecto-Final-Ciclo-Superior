#ifndef _MANUAL_DOOR_CONTROLLER_H
#define _MANUAL_DOOR_CONTROLLER_H

#include "Arduino.h"
#include "Capacity.h"
#include "Common.h"

class ManualDoorController {
public:
  ManualDoorController();

  bool button_option;
  bool read_flag;

  void Setup(bool debug = false);
  bool Read(bool debug);
  void Turn_on_light(bool debug = false);
  void Turn_off_light(bool debug = false);

  bool getButtonOption(bool debug = false);
};
#endif
