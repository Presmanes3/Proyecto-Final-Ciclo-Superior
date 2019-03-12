/* We have a DHT22 connected to pin 25 on Arduino*/

#ifndef _TEMPINT_DHT_H
#define _TEMPINT_DHT_H

#include "Arduino.h"
#include "Common.h"
#include "DHT.h"

class DHT_S {

public:
  DHT_S();

  DHT dht = DHT(DHT_PIN, DHT_TYPE);

  uint32_t Alarm_time_reference;
  uint8_t Alarm_times_activated;
  uint8_t Alarm_thresholds[2];
  bool Alarm_option;

  float Temperature;
  float Humidity;
  float Heat;
  bool State;
  void Update_Temperature();
  void Update_Humidity();
  void Update_Heat();

  void Setup(bool debug = false);
  void Read(bool debug = false);
  /*void Save_SD(char *time, bool header = false, bool debug = false);*/

  bool Alarm();
};

#endif
