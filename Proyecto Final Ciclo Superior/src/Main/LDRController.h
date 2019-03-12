#ifndef _LDR_CONTROLLER_H
#define _LDR_CONTROLLER_H

#include "Arduino.h"
#include "Common.h"

class LDRController {

public:
  LDRController(uint16_t treshold);

  uint16_t threshold;

  void Setup(bool debug = false);
  bool Read(bool debug = false);
  void Light_up(bool debug);
};

#endif
