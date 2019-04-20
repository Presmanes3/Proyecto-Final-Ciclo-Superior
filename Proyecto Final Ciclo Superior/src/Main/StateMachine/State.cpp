#include "State.h"

State::State(StateMachine *_parent) { this->parent = _parent; }

void State::changeState(State *newState) {
  this->parent->changeState(newState);
}
