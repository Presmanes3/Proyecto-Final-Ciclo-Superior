#include "EmerDoor.h"

EmerDoorController::EmerDoorController(TimeManager *timeManager,
                                       Timer *checkTimer, Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer) {
  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
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

void EmerDoorController::turnOnLight(bool debug) {
  if (debug) {
    Serial.println(F("===== Encendiendo Luz Emergencia ====="));
  }
  digitalWrite(EMERGENCY_LED, 1);
}
void EmerDoorController::turnOffLight(bool debug) {
  if (debug) {
    Serial.println(F("===== Apagando Luz Emergencia ====="));
  }
  digitalWrite(EMERGENCY_LED, 0);
}

void EmerDoorController::setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Controlador Puerta Emergencia ====="));
  }
  pinMode(EMERGENCY_DOOR_PIN, INPUT);
  pinMode(EMERGENCY_LED, OUTPUT);
}
bool EmerDoorController::read(bool debug) {
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

void EmerDoorController::run(bool debug) {
  if (this->checkTimer->getFlag()) {
    if (this->timeManager->pastMil(*this->checkTimer)) {
      if (this->read(debug)) {
        this->turnOnLight(debug);
        this->checkTimer->deactivateFlag();
        this->standByTimer->activateFlag();
      }
    }
  }
  if (this->standByTimer->getFlag()) {
    if (this->timeManager->pastMil(*this->standByTimer)) {
      this->turnOffLight(debug);
      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();
    }
  }
}
