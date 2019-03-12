#include "PIRController.h"

PIRController::PIRController() {}

void PIRController::Setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Sensor PIR ====="));
  }
  pinMode(PIR_PIN, INPUT);
}

bool PIRController::Read(bool debug) {
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

void PIRController::Turn_off_light(bool debug) {
  if (debug) {
    Serial.println(F("===== Apagando Luz PIR ====="));
  }
  digitalWrite(PIR_LED, 0);
}

void PIRController::Turn_on_light(bool debug) {
  if (debug) {
    Serial.println(F("===== Encendiendo Luz PIR ====="));
  }
  digitalWrite(PIR_LED, 1);
}
