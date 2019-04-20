#ifndef _EMERGENCY_DOOR_H_
#define _EMERGENCY_DOOR_H_

#include "../Common.h"
#include "Arduino.h"

class ReadState : public State {};
class InactiveState : public State {};
class EmergencyDoorControllerFSM : public StateMachine {};

class EmergencyDoorController : public AbstractSensor {

public:
  EmergencyDoorController();

  /*void Setup(bool debug = false);
  bool Read(bool debug = false);*/
  void Turn_on_light(bool debug = false);
  void Turn_off_light(bool debug = false);

private:
  EmergencyDoorControllerFSM *machine;
};

class EmergencyDoorControllerFSM : public StateMachine {
public:
  EmergencyDoorControllerFSM(EmergencyDoorController *_myController);

private:
  EmergencyDoorController *controller;
  TimeManager *timeManager;
  ReadState *readState;
  InactiveState *inactiveState;
};

class ReadState : public State {
public:
  ReadState(EmergencyDoorControllerFSM *machine);

private:
  Timer readTimer;
  EmergencyDoorControllerFSM *machine;
};

class InactiveState : public State {
public:
  InactiveState(EmergencyDoorControllerFSM *machine);

private:
  Timer inactiveTimer;
  EmergencyDoorControllerFSM *machine;
};

#endif
