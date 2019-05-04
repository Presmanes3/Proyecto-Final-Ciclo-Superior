#include "ManualDoorController.h"

ManualDoorController::ManualDoorController(CapacityManager *capacityManager,
                                           TimeManager *timeManager,
                                           Timer *checkTimer,
                                           Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer){
  this->capacityManager = capacityManager;
  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
}

void ManualDoorController::setup(){
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

bool ManualDoorController::read(){
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

void ManualDoorController::turnOnExitLight(){
#if IN_OUT_MANUAL_DEBUG
  Serial.println(F("===== Encenciendo Led Salida ====="));
#endif
  digitalWrite(MANUAL_OUT_LED, 1);
}
void ManualDoorController::turnOnEnterLight(){
#if IN_OUT_MANUAL_DEBUG
  Serial.println(F("===== Encenciendo Led Entrada ====="));
#endif
  digitalWrite(MANUAL_IN_LED, 1);
}

void ManualDoorController::turnOffExitLight(){
#if IN_OUT_MANUAL_DEBUG
  Serial.println(F("===== Apagando Led Entrada ====="));
#endif
  digitalWrite(MANUAL_OUT_LED, 0);
}
void ManualDoorController::turnOffEnterLight(){
#if IN_OUT_MANUAL_DEBUG
  Serial.println(F("===== Apagando Led Salida ====="));
#endif
  digitalWrite(MANUAL_IN_LED, 0);
}

bool ManualDoorController::getButtonOption(){
#if IN_OUT_MANUAL_DEBUG
  Serial.println(F("===== Devolviendo el valor de Button Option ====="));
#endif
  return this->button_option;
}

void ManualDoorController::run(){
  if (this->checkTimer->getFlag())
  {
    if (this->timeManager->pastMil(*this->checkTimer))
    {
      if (this->read())
      {

        if (this->button_option)
        {
          this->capacityManager->addPerson();
          this->capacityManager->showDataSerial();
          this->turnOnEnterLight();
        }
        else
        {
          this->capacityManager->removePerson();
          this->capacityManager->showDataSerial();
          this->turnOnExitLight();
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
      if (this->button_option)
      {
        this->turnOffEnterLight();
      }
      else
      {
        this->turnOffExitLight();
      }
      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();

      this->checkTimer->updateReference();
    }
  }
}
