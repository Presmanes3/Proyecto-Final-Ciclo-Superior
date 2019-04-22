#include "TempInt_PROBE.h"

PROBE::PROBE(TimeManager *timeManager, Timer *checkTimer, Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer) {
  this->NUM_SENSORS = PROBE_NUM_PROBES;
  this->TEMP_VALUES[1];
  this->State;

  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
}

void PROBE::setup() {
#if TEMP_PROBE_DEBUG
  Serial.println(F("===== Iniciando Sondas de Temperatura ====="));
#endif
  this->sensorDS18B20.begin();
  this->Find_devices();
}
void PROBE::Find_devices() {
  PROBE::NUM_SENSORS = this->sensorDS18B20.getDeviceCount();
  if (PROBE::NUM_SENSORS <= 0) {
    this->State = false;
  } else {
    this->State = true;
  }
#if TEMP_PROBE_DEBUG
  Serial.println(F("Buscando dispositivos"));
  Serial.print(F("Encontrados: "));
  Serial.println(this->NUM_SENSORS);
#endif
}
bool PROBE::read() {
  this->Find_devices();
  if (this->State) {
#if TEMP_PROBE_DEBUG
    Serial.println(F("===== Leyendo Sondas Temperatura ====="));
#endif

    PROBE::sensorDS18B20.requestTemperatures();
    for (uint8_t id = 0; id < this->NUM_SENSORS; id++) {
      this->TEMP_VALUES[id] = this->sensorDS18B20.getTempCByIndex(id);
    }
  } else {
#if TEMP_PROBE_DEBUG
    Serial.println(F("Error, sondas desconectadas\n"));
#endif
  }
  return false;
}
void PROBE::Show() {
#if TEMP_PROBE_DEBUG
  Serial.println(F("===== Mostrando Informacion Temperatura ====="));
  for (uint8_t id = 0; id < this->NUM_SENSORS; id++) {
    Serial.print(F("Sonda Temperatura "));
    Serial.print(id);
    Serial.print(F(" : "));
    Serial.println(this->TEMP_VALUES[id]);
  }
  Serial.println();
#endif
}
/*void PROBE::Save_SD() {
  if (PROBE::State) {
    LOGGUER::Change_dir(LOGGUER::FILES_PATH, debug);
    if (LOGGUER::SD.exists(FILE_PROBES)) {
      #if TEMP_PROBE_DEBUG
        Serial.println(F("Guardando Temp. Ext. sd"));
      }
      LOGGUER::myFile.open(FILE_PROBES, O_APPEND | O_WRITE); // open it
      if (LOGGUER::myFile.fileSize() > 9000) {
        LOGGUER::myFile.close();
        Serial.println(F("El archivo a enviar es mayor de 9Kb"));
      } else {
        LOGGUER::myFile.print(F("Temperature Sensor"));
        LOGGUER::myFile.print(F(","));
        LOGGUER::myFile.print(F("Values\n"));

        for (uint8_t ID = 0; ID < PROBE::NUM_SENSORS; ID++) {
          // for each sensor installed
          #if TEMP_PROBE_DEBUG
            Serial.print(F("Sensor "));
            Serial.print(ID);
            Serial.print(" : ");
            Serial.print(PROBE::TEMP_VALUES[ID]);
            Serial.println("ºC");
          }

          LOGGUER::myFile.print(ID);     // add sensor number
          LOGGUER::myFile.print(F(",")); // next colum

          LOGGUER::myFile.print(PROBE::TEMP_VALUES[ID]); // add temperature
          LOGGUER::myFile.print(F("\n"));
        }

        if (Serial) {
          Serial.println(F("Temp. Ext. guardada\n"));
        }
        LOGGUER::myFile.close();
      }
    } else {
      LOGGUER::Create_file(FILE_PROBES, debug);
      PROBE::Save_SD(debug);
    }
  }
}*/

void PROBE::run() {
  if (this->checkTimer->getFlag()) {
    if (this->timeManager->pastMil(*this->checkTimer)) {
      this->read();
      this->Show();
      this->checkTimer->deactivateFlag();
      this->standByTimer->activateFlag();
    }
  }
  if (this->standByTimer->getFlag()) {
    if (this->timeManager->pastMin(*this->standByTimer)) {
      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();
    }
  }
}
