#include "ManualDoorController.h"

ManualDoorController::ManualDoorController() {}

void ManualDoorController::Setup(bool debug) {
  if (debug) {
    Serial.println(
        F("===== Iniciando Controlador Apertura Manual Puertas ====="));
  }
  pinMode(MANUAL_DOOR_IN_PIN, INPUT);
  pinMode(MANUAL_DOOR_OUT_PIN, INPUT);

  pinMode(MANUAL_IN_LED, OUTPUT);
  pinMode(MANUAL_OUT_LED, OUTPUT);

  ManualDoorController::button_option = false;
  ManualDoorController::read_flag = false;
}

bool ManualDoorController::Read(bool debug) {
  if (debug) {
    Serial.println(
        F("===== Leyendo Controlador Apertura Manual Puertas ====="));
  }
  if (digitalRead(MANUAL_DOOR_IN_PIN)) {
    if (debug) {
      Serial.println(F("Boton Entrada Detectado"));
    }
    ManualDoorController::button_option = true;
    ManualDoorController::read_flag = true;
    return true;
  } else if (digitalRead(MANUAL_DOOR_OUT_PIN)) {
    if (debug) {
      Serial.println(F("Boton Salida Detectado"));
    }
    ManualDoorController::button_option = false;
    ManualDoorController::read_flag = true;
    return true;
  }
  return false;
}

void ManualDoorController::Turn_on_light(bool debug) {
  if (ManualDoorController::read_flag) {
    if (ManualDoorController::button_option) {
      if (debug) {
        Serial.println(F("===== Encenciendo Led Salida ====="));
      }
      digitalWrite(MANUAL_IN_LED, 1);
    } else {
      if (debug) {
        Serial.println(F("===== Encenciendo Led Salida ====="));
      }
      digitalWrite(MANUAL_OUT_LED, 1);
    }
    ManualDoorController::read_flag = false;
  }
}

void ManualDoorController::Turn_off_light(bool debug) {
  if (ManualDoorController::read_flag) {
    if (ManualDoorController::button_option) {
      if (debug) {
        Serial.println(F("===== Apagando Led Salida ====="));
      }
      digitalWrite(MANUAL_IN_LED, 1);
    } else {
      if (debug) {
        Serial.println(F("===== Apagando Led Salida ====="));
      }
      digitalWrite(MANUAL_OUT_LED, 1);
    }
    ManualDoorController::read_flag = false;
  }
}

bool ManualDoorController::getButtonOption(bool debug) {
  if (debug) {
    Serial.println(F("===== Devolviendo el valor de Button Option ====="));
  }
  return ManualDoorController::button_option;
}
