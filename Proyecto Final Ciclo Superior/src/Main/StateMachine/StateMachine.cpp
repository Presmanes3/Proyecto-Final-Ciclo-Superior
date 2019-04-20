#include "StateMachine.h"

StateMachine::StateMachine(State *initialState) {
  this->currentState = initialState;
}

void StateMachine::changeState(State *newState) {
  this->currentState = newState;
}

void StateMachine::updateCurrentState() { this->currentState->update(); }

/*===========================================================*/

State::State(StateMachine *_parent) { this->parent = _parent; }

void State::changeState(State *newState) {
  this->parent->changeState(newState);
}
