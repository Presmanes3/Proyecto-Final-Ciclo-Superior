#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H

class StateMachine;

class State {
public:
  State(StateMachine *_parent = nullptr);

  virtual void update() = 0;
  void changeState(State *newState);

private:
  StateMachine *parent;
};

class StateMachine {
public:
  StateMachine(State *initialState = nullptr);

  void changeState(State *newState);
  void updateCurrentState();

private:
  State *currentState;
};

#endif
