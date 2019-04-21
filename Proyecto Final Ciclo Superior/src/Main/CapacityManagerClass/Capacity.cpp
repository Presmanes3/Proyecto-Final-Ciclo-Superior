#include "Capacity.h"

CapacityManager::CapacityManager(uint32_t maxCapacity) {
  CapacityManager::maxCapacity = maxCapacity;
}

void CapacityManager::Setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Control de aforo ==="));
    Serial.print(F("Aforo Maximo: "));
    Serial.println(this->maxCapacity);
    Serial.println();
  } /*
     pinMode(MANUAL_DOOR_IN_PIN, INPUT);
     pinMode(MANUAL_DOOR_OUT_PIN, INPUT);*/
}

void CapacityManager::Show(bool debug) {
  if (debug) {
    Serial.println(F("===== Mostrando Informacion Aforo ====="));
    Serial.print(F("Aforo Maximo: "));
    Serial.println(this->maxCapacity);
    Serial.print(F("Actualmente hay: "));
    Serial.println(this->currentCustomersIn);
    Serial.println(F("======================================="));
  }
}

void CapacityManager::Add(bool debug) {
  if (debug) {
    Serial.println(F("===== Añadiendo una persona al aforo ====="));
  }
  if (this->currentCustomersIn + 1 < this->maxCapacity) {
    this->currentCustomersIn++;
  } else {
    if (debug) {
      Serial.println(F("No cabe mas gente"));
    }
  }
}

void CapacityManager::Substract(bool debug) {
  if (debug) {
    Serial.println(F("===== Retirando una persona al aforo ====="));
  }
  if (this->currentCustomersIn - 1 >= 0) {
    this->currentCustomersIn--;
  } else {
    if (debug) {
      Serial.println(F("No queda nadie"));
    }
  }
}
