/* We have a DHT22 connected to pin 25 on Arduino*/

#ifndef _TEMPINT_DHT_H
#define _TEMPINT_DHT_H

#include "../Common.h"
#include "Arduino.h"
#include "DHT.h"

class DHT_S : public EventManager, public AbstractSensor {

public:
  DHT_S(TimeManager *timeManager, Timer *checkTimer, Timer *standByTimer);

  void updateTemperature();
  void updateHumidity();
  void updateHeat();

  void run();

  void setup() override;
  bool read() override;
  /*void Save_SD(char *time, bool header = false, );*/

  bool Alarm();
  void Show();

private:
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
