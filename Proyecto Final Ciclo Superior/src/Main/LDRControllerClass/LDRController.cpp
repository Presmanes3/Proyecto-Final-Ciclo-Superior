#include "LDRController.h"

LDRController::LDRController(uint16_t threshold, TimeManager* timeManager,
                             Timer* checkTimer, Timer* standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer) {
  this->checkTimer->activateFlag( );
  this->standByTimer->deactivateFlag( );

  this->threshold = threshold;
}

void LDRController::setup( ) {
#if EXTERNAL_LIGHT_SERIAL_GUI
  Serial.println(F("=========== Iniciando Controlador LDR ============"));
  Serial.print(F("Threshold set at: "));

  float percentaje = LDR_THRESHOLD * 100.0 / 1024.0;

  Serial.print(percentaje, 3);
  Serial.println(F("%"));
  Serial.println(F(SERIAL_SPLITTER));
  Serial.println( );
#endif
  pinMode(LDR_PIN, INPUT);
  pinMode(LDR_LED, OUTPUT);
  this->threshold = LDR_THRESHOLD;
}

bool LDRController::read( ) {
#if EXTERNAL_LIGHT_SERIAL_GUI
  Serial.println(F("============= Leyendo Sensor LDR ============="));
#endif
  uint16_t value = analogRead(LDR_PIN);
  bool     result;
  result = value >= this->threshold;

#if EXTERNAL_LIGHT_SERIAL_GUI
  Serial.print(SERIAL_TAB);
  Serial.println(result ? "LDR Activated" : "LDR Not Activated");
  Serial.println(F(SERIAL_SPLITTER));
  Serial.println( );
#endif
  return result;
}

void LDRController::turnOnLight( ) {
#if EXTERNAL_LIGHT_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Encendiento Luz Exterior"));
#endif
  digitalWrite(LDR_LED, 1);
}

void LDRController::turnOffLight( ) {
#if EXTERNAL_LIGHT_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Apagando Luz Exterior"));
#endif
  digitalWrite(LDR_LED, 0);
}

void LDRController::run( ) {
  if(this->checkTimer->getFlag( )) {
    if(this->timeManager->pastMil(*this->checkTimer)) {
      if(this->read( )) {
        this->turnOnLight( );

        this->checkTimer->deactivateFlag( );
        this->standByTimer->activateFlag( );

        this->standByTimer->updateReferenceMillis( );
      }
    }
  }
  if(this->standByTimer->getFlag( )) {
    if(this->timeManager->pastSec(*this->standByTimer)) {
      this->turnOffLight( );

      this->standByTimer->deactivateFlag( );
      this->checkTimer->activateFlag( );

      this->checkTimer->updateReferenceMillis( );
    }
  }
}

void LDRController::setThreshold(uint16_t newVal) { this->threshold = newVal; }
uint16_t LDRController::getThreshold( ) { return this->threshold; }
