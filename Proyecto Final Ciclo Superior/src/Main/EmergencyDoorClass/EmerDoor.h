#ifndef _EMERGENCY_DOOR_H_
#define _EMERGENCY_DOOR_H_

#include "../Common.h"
#include "Arduino.h"
#include "EmerDoorFSM.h"

class EmerDoorController : AbstractSensor {

public:
  EmerDoorController();

  /*void Setup(bool debug = false);
  bool Read(bool debug = false);*/
  bool read(bool debug = false) override;
  bool setup(bool debug = false) override;

  void Turn_on_light(bool debug = false);
  void Turn_off_light(bool debug = false);

private:
  EmerDoorFSM machine = EmerDoorFSM(&this->machine.readState);
};

#endif
