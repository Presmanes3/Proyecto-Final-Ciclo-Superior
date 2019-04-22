/* We have between 2 and 5 temperature probes connected to pin 26 on Arduino*/

#ifndef _TEMPINT_PROBE_H
#define _TEMPINT_PROBE_H

#include "../Common.h"
#include "Arduino.h"
#include "DallasTemperature.h"
#include "OneWire.h"

class PROBE : public EventManager, public AbstractSensor {
public:
  PROBE(TimeManager *timeManager, Timer *checkTimer, Timer *standByTimer);

  void run();
  void setup() override;
  bool read() override;

  void Find_devices();
  // void Save_SD(\);
  void Show();

private:
  OneWire oneWireObjeto = OneWire(PROBE_DATA_PIN);
  DallasTemperature sensorDS18B20 = DallasTemperature(&oneWireObjeto);
  uint8_t NUM_SENSORS;
  float TEMP_VALUES[5];
  bool State;
};
#endif
