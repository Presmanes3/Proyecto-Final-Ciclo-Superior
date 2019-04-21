#ifndef _EMERGENCY_DOOR_FSM_STATES_H_
#define _EMERGENCY_DOOR_FSM_STATES_H_

#include "../Common.h"
#include "Arduino.h"
//#include "EmerDoorFSM.h"

class EmerDoorFSM;

class ReadState : public State {
public:
  ReadState(EmerDoorFSM *machine);
  void update() override;

private:
  // Timer readTimer;
  EmerDoorFSM *machine;
};

class InactiveState : public State {
public:
  InactiveState(EmerDoorFSM *machine);
  void update() override;

private:
  // Timer inactiveTimer;
  EmerDoorFSM *machine;
};

#endif
