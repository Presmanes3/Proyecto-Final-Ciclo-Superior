#include "CustomProbeClass.h"

CustomProbeClass::CustomProbeClass(TimeManager* timeManager, Timer* checkTimer,
                                   Timer* standByTimer, LcdWrapper* myLcd,
                                   char* frameName)
    : EventManager(timeManager, checkTimer, standByTimer) {
  this->totalProbesConnected = PROBE_NUM_PROBES;

  this->checkTimer->activateFlag( );
  this->standByTimer->deactivateFlag( );

  this->basicFrame = BasicProbeFrame(this, myLcd, frameName);
  this->lcd        = nullptr;
}

void CustomProbeClass::setup( ) {
#if TEMP_PROBE_SERIAL_GUI
  Serial.println(F("========= Iniciando Sondas de Temperatura ========="));
  Serial.println(F(SERIAL_SPLITTER));
  Serial.println( );
#endif
  this->sensorDS18B20.begin( );
  this->findDevices( );
}
void CustomProbeClass::findDevices( ) {
  this->totalProbesConnected = this->sensorDS18B20.getDeviceCount( );
  if(this->totalProbesConnected <= 0) {
    this->State = false;
  } else {
    this->State = true;
  }
#if TEMP_PROBE_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Buscando dispositivos"));
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.print(F("Encontrados: "));
  Serial.println(this->totalProbesConnected);
#endif
}
bool CustomProbeClass::read( ) {
  this->findDevices( );
  if(this->State) {
#if TEMP_PROBE_DEBUG
    Serial.print(F(SERIAL_DEBUG_TAG));
    Serial.println(F("Leyendo Sondas Temperatura"));
#endif

    this->sensorDS18B20.requestTemperatures( );
    for(uint8_t id = 0; id < this->totalProbesConnected; id++) {
      this->probesConnectedValue[id] = this->sensorDS18B20.getTempCByIndex(id);
    }
  } else {
#if TEMP_PROBE_DEBUG
    Serial.print(F(SERIAL_DEBUG_TAG));
    Serial.println(F("Error, sondas desconectadas\n"));
#endif
  }
  return false;
}
void CustomProbeClass::showSerialData( ) {
#if TEMP_PROBE_SERIAL_GUI
  Serial.println(F("======== Mostrando Informacion Temperatura ========"));
  for(uint8_t id = 0; id < this->totalProbesConnected; id++) {
    Serial.print(F(SERIAL_TAB));
    Serial.print(F("Sonda Temperatura "));
    Serial.print(id);
    Serial.print(F(" : "));
    Serial.println(this->probesConnectedValue[id]);
  }
  Serial.println(F(SERIAL_SPLITTER));
  Serial.println( );
#endif
}
/*void CustomProbeClass::Save_SD() {
  if (CustomProbeClass::State) {
    LOGGUER::Change_dir(LOGGUER::FILES_PATH, debug);
    if (LOGGUER::SD.exists(FILE_CustomProbeClassS)) {
      #if TEMP_CustomProbeClass_DEBUG
        Serial.println(F("Guardando Temp. Ext. sd"));
      }
      LOGGUER::myFile.open(FILE_CustomProbeClassS, O_APPEND | O_WRITE); // open
it if (LOGGUER::myFile.fileSize() > 9000) { LOGGUER::myFile.close();
        Serial.println(F("El archivo a enviar es mayor de 9Kb"));
      } else {
        LOGGUER::myFile.print(F("Temperature Sensor"));
        LOGGUER::myFile.print(F(","));
        LOGGUER::myFile.print(F("Values\n"));

        for (uint8_t ID = 0; ID < this->totalProbesConnected; ID++) {
          // for each sensor installed
          #if TEMP_CustomProbeClass_DEBUG
            Serial.print(F("Sensor "));
            Serial.print(ID);
            Serial.print(" : ");
            Serial.print(this->probesConnectedValue[ID]);
            Serial.println("ºC");
          }

          LOGGUER::myFile.print(ID);     // add sensor number
          LOGGUER::myFile.print(F(",")); // next colum

          LOGGUER::myFile.print(this->probesConnectedValue[ID]); // add
temperature LOGGUER::myFile.print(F("\n"));
        }

        if (Serial) {
          Serial.println(F("Temp. Ext. guardada\n"));
        }
        LOGGUER::myFile.close();
      }
    } else {
      LOGGUER::Create_file(FILE_CustomProbeClassS, debug);
      CustomProbeClass::Save_SD(debug);
    }
  }
}*/

void CustomProbeClass::run( ) {
  if(this->checkTimer->getFlag( )) {
    if(this->timeManager->pastSec(*this->checkTimer)) {
      this->read( );
      this->showSerialData( );

#if TEMP_LCD_DEBUG
      this->lcd->clear( );
      this->lcd->changeFrame(&this->basicFrame);
#endif

      this->checkTimer->deactivateFlag( );
      this->standByTimer->activateFlag( );

      this->standByTimer->updateReferenceMillis( );
    }
  }
  if(this->standByTimer->getFlag( )) {
    if(this->timeManager->pastSec(*this->standByTimer)) {

      this->lcd->clear( );
      this->lcd->changeFrame(this->lcd->getDefaultFrame( ));

      this->standByTimer->deactivateFlag( );
      this->checkTimer->activateFlag( );

      this->checkTimer->updateReferenceMillis( );
    }
  }
}

float CustomProbeClass::getTemperatureFromDevice(uint8_t index) {
  return this->probesConnectedValue[index];
}

BasicProbeFrame* CustomProbeClass::getBasicFrame( ) {
  return &this->basicFrame;
}

void CustomProbeClass::setLcd(LcdWrapper* newLcd) {
#if TEMP_PROBE_DEBUG
  Serial.print(F(SERIAL_DEBUG_TAG));
  Serial.println(F("Setting Temp Probe Lcd"));
#endif

  this->lcd = newLcd;
}
