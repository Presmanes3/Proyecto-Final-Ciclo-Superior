#include "Emergency_door.h"

EmergencyDoorController::EmergencyDoorController() {}

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
      Serial.println(F("Sensor Puerta Emergencia Activado"));
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
