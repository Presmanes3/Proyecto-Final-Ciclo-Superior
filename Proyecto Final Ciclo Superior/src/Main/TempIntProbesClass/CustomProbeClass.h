/* We have between 2 and 5 temperature probes connected to pin 26 on Arduino*/

#ifndef _TEMPINT_PROBE_H
#define _TEMPINT_PROBE_H

#include "../Common.h"
#include "Arduino.h"
#include "DallasTemperature.h"
#include "OneWire.h"
#include "BasicProbeFrame.h"

class CustomProbeClass : public EventManager, public AbstractSensor
{
public:
  CustomProbeClass(TimeManager *timeManager, Timer *checkTimer, Timer *standByTimer, LcdWrapper *myLcd = nullptr, char *frameName = nullptr);

  /*This is the update function*/
  void run();
  /*This function must be called at startup*/
  void setup() override;
  /*Returns true if reading has be done*/
  bool read() override;

  /*Returns temperature in Celsius from probe X*/
  float getTemperatureFromDevice(uint8_t index);

  /*Find devices and show them if debug is activated*/
  void findDevices();

  // void Save_SD(\);
  void showSerialData();

private:
  OneWire oneWireObjeto = OneWire(PROBE_DATA_PIN);
  DallasTemperature sensorDS18B20 = DallasTemperature(&oneWireObjeto);
  BasicProbeFrame basicFrame = BasicProbeFrame(this);

  uint8_t totalProbesConnected;
  float probesConnectedValue[5];
  bool State;
};
#endif
