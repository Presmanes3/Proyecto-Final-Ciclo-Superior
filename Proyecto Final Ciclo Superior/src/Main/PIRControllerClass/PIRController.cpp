#include "PIRController.h"

PIRController::PIRController(TimeManager *timeManager, Timer *checkTimer,
                             Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer) {}

void PIRController::setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Sensor PIR ====="));
  }
  pinMode(PIR_PIN, INPUT);
}

bool PIRController::read(bool debug) {
  if (debug) {
    Serial.println(F("===== Leyendo Sensor PIR ====="));
  }
  if (digitalRead(PIR_PIN)) {
    if (debug) {
      Serial.println(F("Sensor PIR Activado"));
    }
    return true;
  }
  return false;
}
void PIRController::turnOnLight(bool debug) {
  if (debug) {
    Serial.println(F("===== Apagando Luz PIR ====="));
  }
  digitalWrite(PIR_LED, 0);
}

void PIRController::turnOffLight(bool debug) {
  if (debug) {
    Serial.println(F("===== Encendiendo Luz PIR ====="));
  }
  digitalWrite(PIR_LED, 1);
}

void PIRController::run(bool debug) {
  if (this->checkTimer->getFlag()) {
    if (this->timeManager->pastSec(*this->checkTimer)) {
      if (this->read(debug)) {
        this->turnOnLight(debug);
        this->checkTimer->deactivateFlag();
        this->standByTimer->activateFlag();
      }
    }
  }
  if (this->standByTimer->getFlag()) {
    if (this->timeManager->pastMin(*this->standByTimer)) {
      this->turnOffLight(debug);
      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();
    }
  }
}
