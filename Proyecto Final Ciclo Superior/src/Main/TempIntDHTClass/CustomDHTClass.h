/* We have a DHT22 connected to pin 25 on Arduino*/

#ifndef _TEMPINT_DHT_H
#define _TEMPINT_DHT_H

#include "../Common.h"
#include "../LCDWrapper/LCDWrapper.h"
#include "Arduino.h"
#include "BasicDHTFrame.h"
#include "DHT.h"

class CustomDHTClass : public EventManager, public AbstractSensor {
  public:
  CustomDHTClass(TimeManager* timeManager, Timer* checkTimer,
                 Timer* standByTimer, LcdWrapper* myLcd,
                 char* frameName = "DHT");

  /*Update temperature variable*/
  void updateTemperature( );

  /*Update humidity variable*/
  void updateHumidity( );

  /*Update heat variable*/
  void updateHeat( );

  /*This is the update function*/
  void run( );

  /*This function must be called at the start*/
  void setup( ) override;

  /*This function update all the readable variables*/
  bool read( ) override;

  /*void Save_SD(char *time, bool header = false, );*/

  bool Alarm( ); // Defined but not implemented correctly, must be changed

  /*If debug, show formated data through Serial Port*/
  void showSerialData( );

  /*Returns Temperature as float*/
  float getTemperature( );

  /*Returns Humidity as float*/
  float getHumidity( );

  /*Return Heat as float*/
  float getHeat( );

  BasicDHTFrame* getBasicFrame( );

  void setLcd(LcdWrapper* newLcd);

  protected:
  BasicDHTFrame basicFrame = BasicDHTFrame(this);
  LcdWrapper*   lcd;
  DHT           dht = DHT(DHT_PIN, DHT_TYPE);

  uint32_t Alarm_time_reference;  // Not used for this project
  uint8_t  Alarm_times_activated; // Not used for this project
  uint8_t  Alarm_thresholds[2];   // Not used for this project
  bool     Alarm_option;          // Not used for this project

  /*Temperature Value*/
  float Temperature;

  /*Humidity Value*/
  float Humidity;

  /*Heal Value*/
  float Heat;

  /*Sensor state*/
  bool State;
};

#endif
