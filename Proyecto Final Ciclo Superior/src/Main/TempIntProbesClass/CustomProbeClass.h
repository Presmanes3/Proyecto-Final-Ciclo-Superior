#ifndef _TEMPINT_PROBE_H
#define _TEMPINT_PROBE_H

#include "../Common.h"
#include "../LCDWrapper/LCDWrapper.h"
#include "Arduino.h"
#include "BasicProbeFrame.h"
#include "DallasTemperature.h"
#include "OneWire.h"

class CustomProbeClass : public EventManager, public AbstractSensor {
  public:
  CustomProbeClass(TimeManager* timeManager, Timer* checkTimer,
                   Timer* standByTimer, LcdWrapper* myLcd,
                   char* frameName = "Probe");

  /*This is the update function*/
  void run( );

  /*This function must be called at startup*/
  void setup( ) override;

  /*Returns true if reading has be done*/
  bool read( ) override;

  /*Returns temperature in Celsius from probe X*/
  float getTemperatureFromDevice(uint8_t index);

  /*Find devices and show them if debug is activated*/
  void findDevices( );

  // void Save_SD(\);
  void showSerialData( );

  BasicProbeFrame* getBasicFrame( );

  void setLcd(LcdWrapper* newLcd);

  private:
  OneWire           oneWireObjeto = OneWire(PROBE_DATA_PIN);
  DallasTemperature sensorDS18B20 = DallasTemperature(&oneWireObjeto);
  BasicProbeFrame   basicFrame    = BasicProbeFrame(this);
  LcdWrapper*       lcd;

  /* Total number of probes coneected to the pin*/
  uint8_t totalProbesConnected;

  /* Probes Values Array*/
  float probesConnectedValue[5];

  bool State;
};
#endif
