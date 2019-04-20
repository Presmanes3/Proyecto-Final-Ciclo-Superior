#ifndef _PIR_CONTROLLER_H
#define _PIR_CONTROLLER_H

#include "../Common.h"
#include "Arduino.h"

class PIRController {

public:
  PIRController();

  void Setup(bool debug = false);
  bool Read(bool debug = false);
  void Turn_on_light(bool debug = false);
  void Turn_off_light(bool debug = false);
};

#endif
