#ifndef _EMERGENCY_DOOR_H_
#define _EMERGENCY_DOOR_H_

#include "Arduino.h"
#include "Common.h"

class EmergencyDoorController {

public:
  EmergencyDoorController();

  void Setup(bool debug = false);
  bool Read(bool debug = false);
  void Turn_on_light(bool debug = false);
  void Turn_off_light(bool debug = false);
};

#endif
