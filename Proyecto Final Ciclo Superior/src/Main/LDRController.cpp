#include "LDRController.h"

LDRController::LDRController(uint16_t treshold) {
  LDRController::threshold = threshold;
}

void LDRController::Setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Controlador LDR ====="));
  }
  pinMode(LDR_PIN, INPUT);
}

bool LDRController::Read(bool debug) {
  if (debug) {
    Serial.println(F("===== Leyendo Sensor LDR ====="));
  }
  uint16_t value = analogRead(LDR_PIN);
  if (value >= LDR_THRESHOLD) {
    return true;
  }
  return false;
}
