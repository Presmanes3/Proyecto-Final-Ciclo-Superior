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
  pinMode(CAPACITY_INPUT_PIN, INPUT);
  pinMode(CAPACITY_OUTPUT_PIN, INPUT);
}
void CapacityManager::Check_Door(bool debug) {}
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
