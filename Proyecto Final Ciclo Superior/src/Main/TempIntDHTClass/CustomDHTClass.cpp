#include "CustomDHTClass.h"

CustomDHTClass::CustomDHTClass(TimeManager *timeManager, Timer *checkTimer, Timer *standByTimer, LcdWrapper *myLcd, char *frameName)
    : EventManager(timeManager, checkTimer, standByTimer)
{

  this->Temperature = 0;
  this->Humidity = 0;
  this->Heat = 0;
  this->State = false;

  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();

  this->basicFrame = BasicDHTFrame(this, myLcd, frameName);
}

void CustomDHTClass::setup()
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

bool CustomDHTClass::read()
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

void CustomDHTClass::updateTemperature()
{
  this->Temperature = this->dht.readTemperature();
}
void CustomDHTClass::updateHumidity() { this->Humidity = this->dht.readHumidity(); }
void CustomDHTClass::updateHeat()
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

bool CustomDHTClass::Alarm()
{
  if (millis() - this->Alarm_time_reference >= (1000 * 60 * 5))
  {
    this->updateTemperature();
    if (this->Temperature > Alarm_thresholds[0])
    {
      this->Alarm_times_activated++;
      this->Alarm_time_reference = millis();
      this->Alarm_option = true;
    }
    else if (this->Temperature < Alarm_thresholds[1])
    {
      this->Alarm_times_activated++;
      this->Alarm_time_reference = millis();
      this->Alarm_option = false;
    }
  }
  this->Alarm_time_reference = millis();
  if (this->Alarm_times_activated >= 5)
  {
    this->Alarm_times_activated = 0;
    return true;
  }
  return false;
}

void CustomDHTClass::showSerialData()
{
#if DHT_DEBUG
  Serial.println(F("===== Mostranso Informacion Sensor Humedad ====="));
  Serial.print(F("Temperatura : "));
  Serial.print(this->Temperature, 3);
  Serial.println(F("ºC"));
  Serial.print(F("Humedad Relativa : "));
  Serial.print(this->Humidity, 3);
  Serial.println(F("%"));
#endif
}

void CustomDHTClass::run()
{
  if (this->checkTimer->getFlag())
  {
    if (this->timeManager->pastMil(*this->checkTimer))
    {
      this->read();
#if DHT_DEBUG
      this->showSerialData();
#endif


      this->checkTimer->deactivateFlag();
      this->standByTimer->activateFlag();

      this->standByTimer->updateReference();
    }
  }
  if (this->standByTimer->getFlag())
  {
    if (this->timeManager->pastMin(*this->standByTimer))
    {

      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();

      this->checkTimer->updateReference();
    }
  }
}

float CustomDHTClass::getTemperature()
{
  return this->Temperature;
}
float CustomDHTClass::getHumidity()
{
  return this->Humidity;
}
float CustomDHTClass::getHeat()
{
  return this->Heat;
}