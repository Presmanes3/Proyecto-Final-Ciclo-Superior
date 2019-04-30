#include "ManualDoorController.h"

ManualDoorController::ManualDoorController(CapacityManager *capacityManager,
                                           TimeManager *timeManager,
                                           Timer *checkTimer,
                                           Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer)
{
  this->capacityManager = capacityManager;
  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
}

void ManualDoorController::setup()
{
#if IN_OUT_MANUAL_DEBUG
  Serial.println(
      F("===== Iniciando Controlador Apertura Manual Puertas ====="));
#endif
  pinMode(MANUAL_DOOR_IN_PIN, INPUT);
  pinMode(MANUAL_DOOR_OUT_PIN, INPUT);

  pinMode(MANUAL_IN_LED, OUTPUT);
  pinMode(MANUAL_OUT_LED, OUTPUT);

  this->button_option = false;
  this->read_flag = false;
}

bool ManualDoorController::read()
{
#if IN_OUT_MANUAL_DEBUG
  Serial.println(F("===== Leyendo Controlador Apertura Manual Puertas ====="));
#endif
  if (digitalRead(MANUAL_DOOR_IN_PIN))
  {
#if IN_OUT_MANUAL_DEBUG
    Serial.println(F("Boton Entrada Detectado"));
#endif
    this->button_option = true;
    this->read_flag = true;
    return true;
  }
  else if (digitalRead(MANUAL_DOOR_OUT_PIN))
  {
#if IN_OUT_MANUAL_DEBUG
    Serial.println(F("Boton Salida Detectado"));
#endif
    this->button_option = false;
    this->read_flag = true;
    return true;
  }
  return false;
}

void ManualDoorController::turnOnLight()
{
  if (this->read_flag)
  {
    if (this->button_option)
    {
#if IN_OUT_MANUAL_DEBUG
      Serial.println(F("===== Encenciendo Led Salida ====="));
#endif
      digitalWrite(MANUAL_IN_LED, 1);
    }
    else
    {
#if IN_OUT_MANUAL_DEBUG
      Serial.println(F("===== Encenciendo Led Salida ====="));
#endif
      digitalWrite(MANUAL_OUT_LED, 1);
    }
    this->read_flag = false;
  }
}

void ManualDoorController::turnOffLight()
{
  if (this->read_flag)
  {
    if (this->button_option)
    {
#if IN_OUT_MANUAL_DEBUG
      Serial.println(F("===== Apagando Led Salida ====="));
#endif
      digitalWrite(MANUAL_IN_LED, 1);
    }
    else
    {
#if IN_OUT_MANUAL_DEBUG
      Serial.println(F("===== Apagando Led Salida ====="));
#endif
      digitalWrite(MANUAL_OUT_LED, 1);
    }
    this->read_flag = false;
  }
}

bool ManualDoorController::getButtonOption()
{
#if IN_OUT_MANUAL_DEBUG
  Serial.println(F("===== Devolviendo el valor de Button Option ====="));
#endif
  return this->button_option;
}

void ManualDoorController::run()
{
  if (this->checkTimer->getFlag())
  {
    if (this->timeManager->pastMil(*this->checkTimer))
    {
      if (this->read())
      {
        this->turnOnLight();

        if (this->button_option)
        {
          this->capacityManager->addPerson();
        }
        else
        {
          this->capacityManager->removePerson();
        }

        this->checkTimer->deactivateFlag();
        this->standByTimer->activateFlag();

        this->standByTimer->updateReference();
      }
    }
  }
  if (this->standByTimer->getFlag())
  {
    if (this->timeManager->pastMil(*this->standByTimer))
    {
      this->turnOffLight();

      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();

      this->checkTimer->updateReference();
    }
  }
}
