#include "Capacity.h"

CapacityManager::CapacityManager(uint32_t maxCapacity) {
  CapacityManager::maxCapacity = maxCapacity;
}

void CapacityManager::Setup() {
#if CAPACITY_DEBUG
  Serial.println(F("===== Iniciando Control de aforo ==="));
  Serial.print(F("Aforo Maximo: "));
  Serial.println(this->maxCapacity);
  Serial.println();
#endif
  /*
    pinMode(MANUAL_DOOR_IN_PIN, INPUT);
    pinMode(MANUAL_DOOR_OUT_PIN, INPUT);*/
}

void CapacityManager::Show() {
#if CAPACITY_DEBUG
  Serial.println(F("===== Mostrando Informacion Aforo ====="));
  Serial.print(F("Aforo Maximo: "));
  Serial.println(this->maxCapacity);
  Serial.print(F("Actualmente hay: "));
  Serial.println(this->currentCustomersIn);
  Serial.println(F("======================================="));
#endif
}

void CapacityManager::Add() {
#if CAPACITY_DEBUG
  Serial.println(F("===== Añadiendo una persona al aforo ====="));
#endif
  if (this->currentCustomersIn + 1 < this->maxCapacity) {
    this->currentCustomersIn++;
  } else {
#if CAPACITY_DEBUG
    Serial.println(F("No cabe mas gente"));
#endif
  }
}

void CapacityManager::Substract() {
#if CAPACITY_DEBUG
  Serial.println(F("===== Retirando una persona al aforo ====="));
#endif
  if (this->currentCustomersIn - 1 >= 0) {
    this->currentCustomersIn--;
  } else {
#if CAPACITY_DEBUG
    Serial.println(F("No queda nadie"));
#endif
  }
}
