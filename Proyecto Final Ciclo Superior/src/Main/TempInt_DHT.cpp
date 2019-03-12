#include "TempInt_DHT.h"

DHT_S::DHT_S() {

  DHT_S::Temperature = 0;
  DHT_S::Humidity = 0;
  DHT_S::Heat = 0;
  DHT_S::State = false;
}

void DHT_S::Setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Sensor Humedad DHT22 ====="));
  }

  DHT_S::dht.begin();
  if (isnan(DHT_S::Humidity || DHT_S::Temperature || DHT_S::Heat)) {
    DHT_S::State = false;
    if (debug) {
      Serial.println(F("DHT_S22 no iniciado\n"));
    }
  } else {
    DHT_S::State = true;
    if (debug) {
      Serial.println(F("DHT_S22 iniciado\n"));
    }
    DHT_S::Alarm_times_activated = 0;
    DHT_S::Alarm_option = false;
    DHT_S::Alarm_time_reference = millis();
  }
}
void DHT_S::Read(bool debug) {
  if (DHT_S::State) {
    if (debug) {
      Serial.println(F("===== Leyendo Sensor Humedad DHT22 ====="));
    }
    DHT_S::Update_Temperature();
    DHT_S::Update_Humidity();
    DHT_S::Update_Heat();

    if (debug) {
      char buff[10];
      dtostrf(DHT_S::Temperature, 3, 2, buff);
      Serial.print(F("Temperatura : "));
      Serial.println(buff);
      dtostrf(DHT_S::Humidity, 3, 2, buff);
      Serial.print(F("Humedad : "));
      Serial.println(buff);
      dtostrf(DHT_S::Heat, 3, 2, buff);
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
  DHT_S::Temperature = DHT_S::dht.readTemperature();
}
void DHT_S::Update_Humidity() { DHT_S::Humidity = DHT_S::dht.readHumidity(); }
void DHT_S::Update_Heat() {
  DHT_S::Heat =
      DHT_S::dht.computeHeatIndex(DHT_S::Temperature, DHT_S::Humidity, false);
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
