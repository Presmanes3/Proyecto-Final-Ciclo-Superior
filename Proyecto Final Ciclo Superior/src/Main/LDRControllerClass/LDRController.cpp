#include "LDRController.h"

LDRController::LDRController(TimeManager *timeManager, Timer *checkTimer,
                             Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer) {
  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
}

void LDRController::setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Controlador LDR ====="));
  }
  pinMode(LDR_PIN, INPUT);
  pinMode(LDR_LED, OUTPUT);
  this->threshold = LDR_THRESHOLD;
}

bool LDRController::read(bool debug) {
  if (debug) {
    Serial.println(F("===== Leyendo Sensor LDR ====="));
  }
  uint16_t value = analogRead(LDR_PIN);
  if (value >= this->threshold) {
    return true;
  }
  return false;
}

void LDRController::turnOnLight(bool debug) {
  if (debug) {
    Serial.println(F("===== Encendiento Luz Exterior ====="));
  }
  digitalWrite(LDR_LED, 1);
}

void LDRController::turnOffLight(bool debug) {
  if (debug) {
    Serial.println(F("===== Apagando Luz Exterior ====="));
  }
  digitalWrite(LDR_LED, 0);
}

void LDRController::run(bool debug) {
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
    if (this->timeManager->pastMin(*this->standByTimer)) {
      this->turnOffLight(debug);
      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();
    }
  }
}

void LDRController::setThreshold(uint16_t newVal) { this->threshold = newVal; }
uint16_t LDRController::getThreshold() { return this->threshold; }
