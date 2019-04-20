#include "StateMachine.h"

StateMachine::StateMachine(State *initialState) {
  this->currentState = initialState;
}

void StateMachine::changeState(State *newState) {
  this->currentState = newState;
}

void StateMachine::update() { this->currentState->update(); }
