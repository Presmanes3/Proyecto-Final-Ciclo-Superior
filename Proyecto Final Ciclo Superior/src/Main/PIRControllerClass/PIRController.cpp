#include "PIRController.h"

PIRController::PIRController(TimeManager *timeManager, Timer *checkTimer,
                             Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer)
{
  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
}

void PIRController::setup()
{
#if SMART_CORRIDOR_LIGHT_DEBUG
  Serial.println(F("===== Iniciando Sensor PIR ====="));
#endif
  pinMode(PIR_PIN, INPUT);
}

bool PIRController::read()
{
#if SMART_CORRIDOR_LIGHT_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Leyendo Sensor PIR"));
#endif
  if (digitalRead(PIR_PIN))
  {
#if SMART_CORRIDOR_LIGHT_DEBUG
    Serial.print(F(SERIAL_DEBUG_TAG));
    Serial.println(F("Sensor PIR Activado"));
#endif
    return true;
  }
  return false;
}
void PIRController::turnOffLight()
{
#if SMART_CORRIDOR_LIGHT_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Apagando Luz PIR"));
#endif
  digitalWrite(PIR_PIN, 0);
}

void PIRController::turnOnLight()
{
#if SMART_CORRIDOR_LIGHT_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Encendiendo Luz PIR"));
#endif
  digitalWrite(PIR_PIN, 1);
}

void PIRController::run()
{
  if (this->checkTimer->getFlag())
  {
    if (this->timeManager->pastSec(*this->checkTimer))
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
    if (this->timeManager->pastSec(*this->standByTimer))
    {
      this->turnOffLight();

      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();

      this->checkTimer->updateReference();
    }
  }
}
