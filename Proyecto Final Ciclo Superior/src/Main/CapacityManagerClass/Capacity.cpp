#include "Capacity.h"

CapacityManager::CapacityManager(uint32_t max_capacity) {
  CapacityManager::max_capacity = max_capacity;
}

void CapacityManager::Setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Control de aforo ==="));
    Serial.print(F("Aforo Maximo: "));
    Serial.println(CapacityManager::max_capacity);
    Serial.println();
  }
  pinMode(MANUAL_DOOR_IN_PIN, INPUT);
  pinMode(MANUAL_DOOR_OUT_PIN, INPUT);
}

void CapacityManager::Show(bool debug) {
  if (debug) {
    Serial.println(F("===== Mostrando Informacion Aforo ====="));
    Serial.print(F("Aforo Maximo: "));
    Serial.println(CapacityManager::max_capacity);
    Serial.print(F("Actualmente hay: "));
    Serial.println(CapacityManager::customers_in);
    Serial.println(F("======================================="));
  }
}

void CapacityManager::Add(bool debug) {
  if (debug) {
    Serial.println(F("===== Añadiendo una persona al aforo ====="));
  }
  if (CapacityManager::customers_in + 1 < CapacityManager::max_capacity) {
    CapacityManager::customers_in++;
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
  if (CapacityManager::customers_in - 1 >= 0) {
    CapacityManager::customers_in--;
  } else {
    if (debug) {
      Serial.println(F("No queda nadie"));
    }
  }
}
