#include "EmerDoor.h"

EmerDoorController::EmerDoorController(TimeManager *timeManager,
                                       Timer *checkTimer, Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer)
{
  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
}

void EmerDoorController::turnOnLight()
{
#if EMER_DOOR_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Encendiendo Luz Emergencia"));
#endif
  digitalWrite(EMERGENCY_LED, 1);
}
void EmerDoorController::turnOffLight()
{
#if EMER_DOOR_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Apagando Luz Emergencia"));
#endif
  digitalWrite(EMERGENCY_LED, 0);
}

void EmerDoorController::setup()
{
#if EMER_DOOR_SERIAL_GUI
  Serial.println(F("======= Iniciando Controlador Puerta Emergencia ======="));
  Serial.println(F(SERIAL_SPLITTER));
  Serial.println();
#endif
  pinMode(EMERGENCY_DOOR_PIN, INPUT);
  pinMode(EMERGENCY_LED, OUTPUT);
}
bool EmerDoorController::read()
{
#if EMER_DOOR_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Leyendo Sensor Puerta Emergencia"));
#endif
  if (digitalRead(EMERGENCY_DOOR_PIN))
  {
#if EMER_DOOR_DEBUG
    Serial.print(F(SERIAL_DEBUG_TAG));
    Serial.println(F("Puerta de emergencia abierta"));
#endif
    return true;
  }
  return false;
}

void EmerDoorController::run()
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
    if (this->timeManager->pastSec(*this->standByTimer))
    {
      this->turnOffLight();

      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();

      this->checkTimer->updateReference();
    }
  }
}
