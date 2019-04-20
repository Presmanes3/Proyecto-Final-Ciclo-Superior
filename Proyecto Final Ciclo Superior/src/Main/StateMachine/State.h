#ifndef _STATE_H_
#define _STATE_H_

#include "StateMachine.h"

class State {
public:
  State(StateMachine *_parent);

  virtual void update() = 0;
  void changeState(State *newState);

private:
  StateMachine *parent;
};

#endif
