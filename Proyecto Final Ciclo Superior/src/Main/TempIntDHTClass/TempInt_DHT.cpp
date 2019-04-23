#include "TempInt_DHT.h"

DHT_S::DHT_S(TimeManager *timeManager, Timer *checkTimer, Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer)
{

  this->Temperature = 0;
  this->Humidity = 0;
  this->Heat = 0;
  this->State = false;

  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
}

void DHT_S::setup()
{
#if DHT_DEBUG
  Serial.println(F("===== Iniciando Sensor Humedad DHT22 ====="));
#endif

  this->dht.begin();
  if (isnan(this->Humidity || this->Temperature || this->Heat))
  {
    this->State = false;
#if DHT_DEBUG
    Serial.println(F("DHT_S22 no iniciado\n"));
#endif
    return;
  }

  else
  {
    this->State = true;
#if DHT_DEBUG
    Serial.println(F("DHT_S22 iniciado\n"));
#endif
  }
  this->Alarm_times_activated = 0;
  this->Alarm_option = false;
  this->Alarm_time_reference = millis();
}

bool DHT_S::read()
{
  if (this->State)
  {
#if DHT_DEBUG
    Serial.println(F("===== Leyendo Sensor Humedad DHT22 ====="));
#endif
    this->updateTemperature();
    this->updateHumidity();
    this->updateHeat();

#if DHT_DEBUG
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
    Serial.println(F("====================================="));
#endif
  }
  return true;
}

void DHT_S::updateTemperature()
{
  this->Temperature = this->dht.readTemperature();
}
void DHT_S::updateHumidity() { this->Humidity = this->dht.readHumidity(); }
void DHT_S::updateHeat()
{
  this->Heat =
      this->dht.computeHeatIndex(this->Temperature, this->Humidity, false);
}

/*void DHT_S::Save_SD(char *time, bool header, ) {
  if (DHT_S::State) {
    LOGGUER::Change_dir(LOGGUER::FILES_PATH, true);
    if (LOGGUER::SD.exists(FILE_TEMPINT)) {
      #if DHT_DEBUG
        Serial.println(
            F("===== Guardando Temperatura Interior DHT22 SD ====="));
      }
      LOGGUER::myFile.open(FILE_TEMPINT, O_APPEND | O_WRITE);
      if (LOGGUER::myFile.fileSize() > 9000) {
        LOGGUER::myFile.close();
        #if DHT_DEBUG
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

bool DHT_S::Alarm()
{
  if (millis() - DHT_S::Alarm_time_reference >= (1000 * 60 * 5))
  {
    DHT_S::updateTemperature();
    if (DHT_S::Temperature > Alarm_thresholds[0])
    {
      DHT_S::Alarm_times_activated++;
      DHT_S::Alarm_time_reference = millis();
      DHT_S::Alarm_option = true;
    }
    else if (DHT_S::Temperature < Alarm_thresholds[1])
    {
      DHT_S::Alarm_times_activated++;
      DHT_S::Alarm_time_reference = millis();
      DHT_S::Alarm_option = false;
    }
  }
  DHT_S::Alarm_time_reference = millis();
  if (DHT_S::Alarm_times_activated >= 5)
  {
    DHT_S::Alarm_times_activated = 0;
    return true;
  }
  return false;
}

void DHT_S::Show()
{
  Serial.println(F("===== Mostranso Informacion Sensor Humedad ====="));
  Serial.print(F("Temperatura : "));
  Serial.print(DHT_S::Temperature, 3);
  Serial.println(F("ºC"));
  Serial.print(F("Humedad Relativa : "));
  Serial.print(DHT_S::Humidity, 3);
  Serial.println(F("%"));
}

void DHT_S::run()
{
  if (this->checkTimer->getFlag())
  {
    if (this->timeManager->pastMil(*this->checkTimer))
    {
      this->read();
      this->Show();
      this->checkTimer->deactivateFlag();
      this->standByTimer->activateFlag();
    }
  }
  if (this->standByTimer->getFlag())
  {
    if (this->timeManager->pastMin(*this->standByTimer))
    {

      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();
    }
  }
}
