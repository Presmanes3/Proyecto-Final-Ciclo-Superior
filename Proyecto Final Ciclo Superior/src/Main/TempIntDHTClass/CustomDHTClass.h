/* We have a DHT22 connected to pin 25 on Arduino*/

#ifndef _TEMPINT_DHT_H
#define _TEMPINT_DHT_H

#include "../Common.h"
#include "Arduino.h"
#include "DHT.h"
#include "BasicDHTFrame.h"

class CustomDHTClass : public EventManager, public AbstractSensor
{
public:
  CustomDHTClass(TimeManager *timeManager, Timer *checkTimer, Timer *standByTimer, LcdWrapper *myLcd = nullptr, char *frameName = nullptr);

  /*Update temperature variable*/
  void updateTemperature();
  /*Update humidity variable*/
  void updateHumidity();
  /*Update heat variable*/
  void updateHeat();

  /*This is the update function*/
  void run();

  /*This function must be called at the start*/
  void setup() override;
  /*This function update all the readable variables*/
  bool read() override;
  /*void Save_SD(char *time, bool header = false, );*/

  bool Alarm();

  /*If debug, show formated data through Serial Port*/
  void showSerialData();

  /*Returns Temperature as float*/
  float getTemperature();
  /*Returns Humidity as float*/
  float getHumidity();
  /*Return Heat as float*/
  float getHeat();

protected:
  BasicDHTFrame basicFrame = BasicDHTFrame(this);
  DHT dht = DHT(DHT_PIN, DHT_TYPE);

  uint32_t Alarm_time_reference;
  uint8_t Alarm_times_activated;
  uint8_t Alarm_thresholds[2];
  bool Alarm_option;

  float Temperature;
  float Humidity;
  float Heat;
  bool State;
};

#endif
