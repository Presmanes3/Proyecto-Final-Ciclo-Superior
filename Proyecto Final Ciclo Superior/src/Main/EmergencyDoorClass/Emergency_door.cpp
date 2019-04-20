#include "Emergency_door.h"

EmergencyDoorController::EmergencyDoorController() {
  this->machine = EmergencyDoorControllerFSM(this);
}
/*
void EmergencyDoorController::Setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Controlador Puerta Emergencia ====="));
  }
  pinMode(EMERGENCY_DOOR_PIN, INPUT);
  pinMode(EMERGENCY_LED, OUTPUT);
}

bool EmergencyDoorController::Read(bool debug) {
  if (debug) {
    Serial.println(F("===== Leyendo Sensor Puerta Emergencia ====="));
  }
  if (digitalRead(EMERGENCY_DOOR_PIN)) {
    if (debug) {
      Serial.println(F("Puerta de emergencia abierta"));
    }
    return true;
  }
  return false;
}

void EmergencyDoorController::Turn_off_light(bool debug) {
  if (debug) {
    Serial.println(F("===== Apagando Luz Emergencia ====="));
  }
  digitalWrite(EMERGENCY_LED, 0);
}

void EmergencyDoorController::Turn_on_light(bool debug) {
  if (debug) {
    Serial.println(F("===== Encendiendo Luz Emergencia ====="));
  }
  digitalWrite(EMERGENCY_LED, 1);
}
*/

void EmergencyDoorController::setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Controlador Puerta Emergencia ====="));
  }
  pinMode(EMERGENCY_DOOR_PIN, INPUT);
  pinMode(EMERGENCY_LED, OUTPUT);
}
void EmergencyDoorController::read(bool debug) {
  if (debug) {
    Serial.println(F("===== Leyendo Sensor Puerta Emergencia ====="));
  }
  if (digitalRead(EMERGENCY_DOOR_PIN)) {
    if (debug) {
      Serial.println(F("Puerta de emergencia abierta"));
    }
    this->changeState(this->inectiveState);
  }
  return;
}

/*========== EmergencyDoorControllerFSM ==========*/
EmergencyDoorControllerFSM::EmergencyDoorControllerFSM(
    EmergencyDoorController *_myController) {

  this->controller = _myController;

  this->timeManager = TimeManager();

  this->ReadState = ReadState(this);
  this->inactiveState = InactiveState(this);
}

/*========== ReadState ==========*/
ReadState::ReadState(EmergencyDoorControllerFSM *machine) {
  this->readTimer = Timer(TIME_TO_CHECK_EMERGENCY_DOOR,
                          INACTIVE_TIME_EMERGENCY_DOOR, millis(), true);
  this->machine = machine;
}

void ReadState::update() { this->machine->controller->read(); }

/*========== InactiveState ==========*/
InactiveState::InactiveState(EmergencyDoorControllerFSM *machine) {
  this->inactiveTimer = Timer(INACTIVE_TIME_EMERGENCY_DOOR,
                              TIME_TO_CHECK_EMERGENCY_DOOR, millis(), true);
  this->machine = machine;
}
