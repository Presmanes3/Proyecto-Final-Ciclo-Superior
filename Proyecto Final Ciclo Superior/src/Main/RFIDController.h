#ifndef _RFID_CONTROLLER_H
#define _RFID_CONTROLLER_H

#include "Arduino.h"
#include "Common.h"

class RFIDController {

public:
  RFIDController();

  void Setup(bool debug = false);
};

#endif
