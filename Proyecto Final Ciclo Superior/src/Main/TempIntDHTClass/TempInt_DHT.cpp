#include "TempInt_DHT.h"

DHT_S::DHT_S(TimeManager *timeManager, Timer *checkTimer, Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer) {

  this->Temperature = 0;
  this->Humidity = 0;
  this->Heat = 0;
  this->State = false;

  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
}

void DHT_S::setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Sensor Humedad DHT22 ====="));
  }

  this->dht.begin();
  if (isnan(this->Humidity || this->Temperature || this->Heat)) {
    this->State = false;
    if (debug) {
      Serial.println(F("DHT_S22 no iniciado\n"));
    }
    return;
  } else {
    this->State = true;
    if (debug) {
      Serial.println(F("DHT_S22 iniciado\n"));
    }
    this->Alarm_times_activated = 0;
    this->Alarm_option = false;
    this->Alarm_time_reference = millis();
  }
}
bool DHT_S::read(bool debug) {
  if (this->State) {
    if (debug) {
      Serial.println(F("===== Leyendo Sensor Humedad DHT22 ====="));
    }
    this->Update_Temperature();
    this->Update_Humidity();
    this->Update_Heat();

    if (debug) {
      char buff[10];
      dtostrf(this->Temperature, 3, 2, buff);
      Serial.print(F("Temperatura : "));
      Serial.println(buff);
      dtostrf(this->Humidity, 3, 2, buff);
      Serial.print(F("Humedad : "));
      Serial.println(buff);
      dtostrf(this->Heat, 3, 2, buff);
      Serial.print(F("Calor : "));
      Serial.println(buff);
      Serial.println();

      if (debug) {
        Serial.println(F("====================================="));
      }
    }
  }
}
void DHT_S::Update_Temperature() {
  this->Temperature = this->dht.readTemperature();
}
void DHT_S::Update_Humidity() { this->Humidity = this->dht.readHumidity(); }
void DHT_S::Update_Heat() {
  this->Heat =
      this->dht.computeHeatIndex(this->Temperature, this->Humidity, false);
}
/*void DHT_S::Save_SD(char *time, bool header, bool debug) {
  if (DHT_S::State) {
    LOGGUER::Change_dir(LOGGUER::FILES_PATH, true);
    if (LOGGUER::SD.exists(FILE_TEMPINT)) {
      if (debug) {
        Serial.println(
            F("===== Guardando Temperatura Interior DHT22 SD ====="));
      }
      LOGGUER::myFile.open(FILE_TEMPINT, O_APPEND | O_WRITE);
      if (LOGGUER::myFile.fileSize() > 9000) {
        LOGGUER::myFile.close();
        if (debug) {
          Serial.println(F("El archivo es mayor de 9kB"));
        }
      } else {
        if (header) {
          LOGGUER::myFile.print(F("Tiempo,Humedad,Temperatura,Calor\n"));
        }
        LOGGUER::myFile.print(time);
        LOGGUER::myFile.print(F(","));
        LOGGUER::myFile.print(DHT_S::Humidity);
        LOGGUER::myFile.print(F(","));
        LOGGUER::myFile.print(DHT_S::Temperature);
        LOGGUER::myFile.print(F(","));
        LOGGUER::myFile.print(DHT_S::Heat);
        LOGGUER::myFile.print(F("\n"));
        LOGGUER::myFile.close();

        if (Serial) {
          Serial.println(F("Temperatura Interior DHT22 guardada\n"));
        }
      }
    } else {
      LOGGUER::Create_file(FILE_TEMPINT, debug);
      DHT_S::Save_SD(time, true, debug);
    }
  }
}*/

bool DHT_S::Alarm() {
  if (millis() - DHT_S::Alarm_time_reference >= (1000 * 60 * 5)) {
    DHT_S::Update_Temperature();
    if (DHT_S::Temperature > Alarm_thresholds[0]) {
      DHT_S::Alarm_times_activated++;
      DHT_S::Alarm_time_reference = millis();
      DHT_S::Alarm_option = true;

    } else if (DHT_S::Temperature < Alarm_thresholds[1]) {
      DHT_S::Alarm_times_activated++;
      DHT_S::Alarm_time_reference = millis();
      DHT_S::Alarm_option = false;
    }
  }
  DHT_S::Alarm_time_reference = millis();
  if (DHT_S::Alarm_times_activated >= 5) {
    DHT_S::Alarm_times_activated = 0;
    return true;
  }
  return false;
}

void DHT_S::Show() {
  Serial.println(F("===== Mostranso Informacion Sensor Humedad ====="));
  Serial.print(F("Temperatura : "));
  Serial.print(DHT_S::Temperature, 3);
  Serial.println(F("ºC"));
  Serial.print(F("Humedad Relativa : "));
  Serial.print(DHT_S::Humidity, 3);
  Serial.println(F("%"));
}

void DHT_S::run(bool debug) {
  if (this->checkTimer->getFlag()) {
    if (this->timeManager->pastMil(*this->checkTimer)) {
      this->read(debug);
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
