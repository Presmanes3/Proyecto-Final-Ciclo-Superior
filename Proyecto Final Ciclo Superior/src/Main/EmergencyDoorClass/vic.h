#include "Arduino.h"

// Super State Machine FW-Declaration
class SuperMachine;

// Super Machine Abstract State
class SuperMachineState {
private:
  SuperMachine *machine;

public:
  virtual void update() = 0;
};

// Super State Machine
class SuperMachine {
  // It's current state
  SuperMachineState *superCurrentState;
  // It's states
  // std::vector<SuperMachineState> superStates;

  void setState(SuperMachineState *superNewState);

  void update() { superCurrentState->update(); }
};

// Supra State Machine FW-Declaration
class SupraMachineState;

// Supra Machine Abstract State
class SupraMachineStateState {
private:
  SupraMachineState *machine;

public:
  virtual void update() = 0;
};

// Supra State Machine IS-A Super Machine State
class SupraMachineState : public SuperMachineState {
  SupraMachineStateState *supraCurrentState;
  // std::vector<SupraMachineStateState> states;

  void setState(SupraMachineStateState *newState);

  // This update is the Super Machine State Implementation
  // This is called by the Super Machine State if its
  //      current state is a Supra Machine State.
  // So a Super Machine State receives a call to update.
  //      it passed the update call to it's state
  //      if it's state is a Supra Machine State
  //      the call will call to it's current supraState
  void update() { supraCurrentState->update(); }
};

// State of the Super Machine State
class SuperState1 : SuperMachineState {};

// State of the Supra Machine State
class SupraState1 : SupraMachineState {};
