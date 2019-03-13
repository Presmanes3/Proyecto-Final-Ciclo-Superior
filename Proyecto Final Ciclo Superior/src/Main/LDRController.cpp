#include "LDRController.h"

LDRController::LDRController(uint16_t treshold) {
  LDRController::threshold = threshold;
}

void LDRController::Setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Controlador LDR ====="));
  }
  pinMode(LDR_PIN, INPUT);
  pinMode(LDR_LED, OUTPUT);
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

void LDRController::Turn_on_light(bool debug) {
  if (debug) {
    Serial.println(F("===== Encendiento Luz Exterior ====="));
  }
  digitalWrite(LDR_LED, 1);
}

void LDRController::Turn_off_light(bool debug) {
  if (debug) {
    Serial.println(F("===== Apagando Luz Exterior ====="));
  }
  digitalWrite(LDR_LED, 0);
}
