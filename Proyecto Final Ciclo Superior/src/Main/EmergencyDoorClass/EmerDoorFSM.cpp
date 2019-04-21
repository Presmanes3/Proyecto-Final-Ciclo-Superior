#include "EmerDoorFSM.h"
#include "EmerDoorFSMStates.h"

EmerDoorFSM::EmerDoorFSM(State *initialState) : StateMachine(initialState) {

  // this->controller = _myController;

  this->timeManager = TimeManager();

  // this->readState = ReadState(this);
  // this->inactiveState = InactiveState(this);
}
