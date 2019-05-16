#include "PIRController.h"

PIRController::PIRController(TimeManager* timeManager, Timer* checkTimer,
                             Timer* standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer) {
  this->checkTimer->activateFlag( );
  this->standByTimer->deactivateFlag( );
}

void PIRController::setup( ) {
#if SMART_CORRIDOR_LIGHT_SERIAL_GUI
  Serial.println(F("============= Iniciando Sensor PIR ============="));
  Serial.println(F(SERIAL_SPLITTER));
  Serial.println( );
#endif
  pinMode(PIR_PIN, INPUT);
  pinMode(PIR_LED, OUTPUT);
}

bool PIRController::read( ) {
#if SMART_CORRIDOR_LIGHT_SERIAL_GUI
  Serial.println(F("============= Leyendo Sensor PIR ============="));
#endif
  bool result = digitalRead(PIR_PIN);

#if SMART_CORRIDOR_LIGHT_SERIAL_GUI
  Serial.print(F(SERIAL_TAB));
  Serial.println(result ? "PIR Activated" : "PIR Not Activated");
  Serial.println(F(SERIAL_SPLITTER));
  Serial.println( );
#endif

  return result;
}
void PIRController::turnOffLight( ) {
#if SMART_CORRIDOR_LIGHT_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Apagando Luz PIR"));
#endif
  digitalWrite(PIR_LED, 0);
}

void PIRController::turnOnLight( ) {
#if SMART_CORRIDOR_LIGHT_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Encendiendo Luz PIR"));
#endif
  digitalWrite(PIR_LED, 1);
}

void PIRController::run( ) {
  if(this->checkTimer->getFlag( )) {
    if(this->timeManager->pastSec(*this->checkTimer)) {
      if(this->read( )) {
        this->turnOnLight( );

        this->checkTimer->deactivateFlag( );
        this->standByTimer->activateFlag( );

        this->standByTimer->updateReference( );
      }
    }
  }
  if(this->standByTimer->getFlag( )) {
    if(this->timeManager->pastSec(*this->standByTimer)) {
      this->turnOffLight( );

      this->standByTimer->deactivateFlag( );
      this->checkTimer->activateFlag( );

      this->checkTimer->updateReference( );
    }
  }
}
