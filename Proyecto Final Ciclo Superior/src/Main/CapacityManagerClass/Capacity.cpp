#include "Capacity.h"

CapacityManager::CapacityManager(uint32_t max_capacity, LcdWrapper *myLcd, char *frameName)
{
  this->maxCapacity = max_capacity;
  this->currentCustomersIn = 0;
  this->basicFrame = BasicCapacityManagerFrame(this, myLcd, frameName);
}

void CapacityManager::setup()
{
#if CAPACITY_SERIAL_GUI
  Serial.println(F("=========== Iniciando Control de aforo ============"));
  Serial.print(F(SERIAL_TAB));
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
#if CAPACITY_SERIAL_GUI
  Serial.println();
  Serial.println(F("========== Mostrando Informacion Aforo ==========="));
  Serial.print(F(SERIAL_TAB));
  Serial.print(F("Aforo Maximo: "));
  Serial.print(this->maxCapacity);
  Serial.println(F(" presonas."));
  Serial.print(F(SERIAL_TAB));
  Serial.print(F("Actualmente hay: "));
  Serial.print(this->currentCustomersIn);
  Serial.println(F(" personas."));
  Serial.println(F(SERIAL_SPLITTER));
  Serial.println();
#endif
}

void CapacityManager::addPerson()
{

  if (this->currentCustomersIn + 1 <= this->maxCapacity)
  {
#if CAPACITY_DEBUG
    Serial.print(F(SERIAL_DEBUG_TAG));
    Serial.println(F("Añadiendo una persona al aforo"));
#endif

    this->currentCustomersIn++;
  }
  else
  {
#if CAPACITY_DEBUG
    Serial.print(F(SERIAL_DEBUG_TAG));
    Serial.println(F("No cabe mas gente"));
#endif
  }
}

void CapacityManager::removePerson()
{

  if (!this->currentCustomersIn == 0)
  {
#if CAPACITY_DEBUG
    Serial.print(F(SERIAL_DEBUG_TAG));
    Serial.println(F("Retirando una persona al aforo ====="));
#endif

    this->currentCustomersIn--;
  }
  else
  {
#if CAPACITY_DEBUG
    Serial.print(F(SERIAL_DEBUG_TAG));
    Serial.println(F("No queda nadie"));
#endif
  }
}
