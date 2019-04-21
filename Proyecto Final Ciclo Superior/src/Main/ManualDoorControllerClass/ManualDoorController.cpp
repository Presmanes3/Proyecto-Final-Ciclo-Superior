#include "ManualDoorController.h"

ManualDoorController::ManualDoorController(CapacityManager *capacityManager,
                                           TimeManager *timeManager,
                                           Timer *checkTimer,
                                           Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer) {
  this->capacityManager = capacityManager;
  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
}

void ManualDoorController::setup(bool debug) {
  if (debug) {
    Serial.println(
        F("===== Iniciando Controlador Apertura Manual Puertas ====="));
  }
  pinMode(MANUAL_DOOR_IN_PIN, INPUT);
  pinMode(MANUAL_DOOR_OUT_PIN, INPUT);

  pinMode(MANUAL_IN_LED, OUTPUT);
  pinMode(MANUAL_OUT_LED, OUTPUT);

  this->button_option = false;
  this->read_flag = false;
}

bool ManualDoorController::read(bool debug) {
  if (debug) {
    Serial.println(
        F("===== Leyendo Controlador Apertura Manual Puertas ====="));
  }
  if (digitalRead(MANUAL_DOOR_IN_PIN)) {
    if (debug) {
      Serial.println(F("Boton Entrada Detectado"));
    }
    this->button_option = true;
    this->read_flag = true;
    return true;
  } else if (digitalRead(MANUAL_DOOR_OUT_PIN)) {
    if (debug) {
      Serial.println(F("Boton Salida Detectado"));
    }
    this->button_option = false;
    this->read_flag = true;
    return true;
  }
  return false;
}

void ManualDoorController::turnOnLight(bool debug) {
  if (this->read_flag) {
    if (this->button_option) {
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
    this->read_flag = false;
  }
}

void ManualDoorController::turnOffLight(bool debug) {
  if (this->read_flag) {
    if (this->button_option) {
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
    this->read_flag = false;
  }
}

bool ManualDoorController::getButtonOption(bool debug) {
  if (debug) {
    Serial.println(F("===== Devolviendo el valor de Button Option ====="));
  }
  return this->button_option;
}

void ManualDoorController::run(bool debug) {
  if (this->checkTimer->getFlag()) {
    if (this->timeManager->pastMil(*this->checkTimer)) {
      if (this->read(debug)) {
        this->turnOnLight(debug);

        if (this->button_option) {
          this->capacityManager->Add(debug);
        } else {
          this->capacityManager->Substract(debug);
        }
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
