#include "EmerDoor.h"
#include "EmerDoorFSM.h"
#include "EmerDoorFSMStates.h"

/*========== ReadState ==========*/
ReadState::ReadState(EmerDoorFSM *machine) : State(machine) {

  /* this->readTimer = Timer(TIME_TO_CHECK_EMERGENCY_DOOR,
                           INACTIVE_TIME_EMERGENCY_DOOR, millis(), true);*/
  this->machine = machine;
}

void ReadState::update() { this->machine->controller->read(); }

/*========== InactiveState ==========*/
InactiveState::InactiveState(EmerDoorFSM *machine) : State(machine) {
  /* this->inactiveTimer = Timer(INACTIVE_TIME_EMERGENCY_DOOR,
                               TIME_TO_CHECK_EMERGENCY_DOOR, millis(), true);*/
  this->machine = machine;
}
