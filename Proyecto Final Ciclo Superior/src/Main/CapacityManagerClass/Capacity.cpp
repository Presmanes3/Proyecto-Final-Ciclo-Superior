#include "Capacity.h"

CapacityManager::CapacityManager(uint32_t max_capacity, LcdWrapper *myLcd, char *frameName)
{
  CapacityManager::maxCapacity = maxCapacity;
  this->simpleFrame = SimpleCapacityManagerFrame(this, myLcd, frameName);
}

void CapacityManager::setup()
{
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

void CapacityManager::showDataSerial()
{
#if CAPACITY_DEBUG
  Serial.println(F("===== Mostrando Informacion Aforo ====="));
  Serial.print(F("Aforo Maximo: "));
  Serial.println(this->maxCapacity);
  Serial.print(F("Actualmente hay: "));
  Serial.println(this->currentCustomersIn);
  Serial.println(F("======================================="));
#endif
}

void CapacityManager::addPerson()
{
#if CAPACITY_DEBUG
  Serial.println(F("===== Añadiendo una persona al aforo ====="));
#endif
  if (this->currentCustomersIn + 1 < this->maxCapacity)
  {
    this->currentCustomersIn++;
  }
  else
  {
#if CAPACITY_DEBUG
    Serial.println(F("No cabe mas gente"));
#endif
  }
}

void CapacityManager::removePerson()
{
#if CAPACITY_DEBUG
  Serial.println(F("===== Retirando una persona al aforo ====="));
#endif
  if (this->currentCustomersIn - 1 >= 0)
  {
    this->currentCustomersIn--;
  }
  else
  {
#if CAPACITY_DEBUG
    Serial.println(F("No queda nadie"));
#endif
  }
}
