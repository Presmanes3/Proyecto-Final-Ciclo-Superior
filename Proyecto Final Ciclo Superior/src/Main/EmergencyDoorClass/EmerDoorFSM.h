#ifndef _EMERGENCY_DOOR_FSM_H_
#define _EMERGENCY_DOOR_FSM_H_

class EmerDoorController;

#include "../Common.h"
#include "Arduino.h"
#include "EmerDoorFSMStates.h"

class EmerDoorFSM : public StateMachine {
public:
  EmerDoorFSM(State *initialState = nullptr);

  EmerDoorController *controller;
  TimeManager timeManager;
  ReadState readState = ReadState(this);
  InactiveState inactiveState = InactiveState(this);
};

#endif
