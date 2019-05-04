#include "LDRController.h"

LDRController::LDRController(TimeManager *timeManager, Timer *checkTimer,
                             Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer)
{
  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
}

void LDRController::setup()
{
#if EXTERNAL_LIGHT_DEBUG
  Serial.println(F("===== Iniciando Controlador LDR ====="));
#endif
  pinMode(LDR_PIN, INPUT);
  pinMode(LDR_LED, OUTPUT);
  this->threshold = LDR_THRESHOLD;
}

bool LDRController::read()
{
#if EXTERNAL_LIGHT_DEBUG
  Serial.println(F(">>>>> Leyendo Sensor LDR"));
#endif
  uint16_t value = analogRead(LDR_PIN);
  if (value >= this->threshold)
  {
    return true;
  }
  return false;
}

void LDRController::turnOnLight()
{
#if EXTERNAL_LIGHT_DEBUG
  Serial.println(F(">>>>> Encendiento Luz Exterior"));
#endif
  digitalWrite(LDR_LED, 1);
}

void LDRController::turnOffLight()
{
#if EXTERNAL_LIGHT_DEBUG
  Serial.println(F(">>>>> Apagando Luz Exterior"));
#endif
  digitalWrite(LDR_LED, 0);
}

void LDRController::run()
{
  if (this->checkTimer->getFlag())
  {
    if (this->timeManager->pastMil(*this->checkTimer))
    {
      if (this->read())
      {
        this->turnOnLight();

        this->checkTimer->deactivateFlag();
        this->standByTimer->activateFlag();

        this->standByTimer->updateReference();
      }
    }
  }
  if (this->standByTimer->getFlag())
  {
    if (this->timeManager->pastMin(*this->standByTimer))
    {
      this->turnOffLight();

      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();

      this->checkTimer->updateReference();
    }
  }
}

void LDRController::setThreshold(uint16_t newVal) { this->threshold = newVal; }
uint16_t LDRController::getThreshold() { return this->threshold; }
