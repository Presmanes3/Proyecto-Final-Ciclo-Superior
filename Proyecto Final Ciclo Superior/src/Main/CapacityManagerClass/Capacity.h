#ifndef _AFORO_H_
#define _AFORO_H_

#include "../Common.h"
#include "../LCDWrapper/LCDWrapper.h"
#include "Arduino.h"
#include "BasicCapacityManagerFrame.h"

class CapacityManager {
  public:
  CapacityManager(uint32_t max_capacity, LcdWrapper* myLcd,
                  char* frameName = "Capacity");

  uint32_t maxCapacity;
  uint32_t currentCustomersIn;

  /*This function must be called at the setup*/
  void setup( );

  /*Adds a person*/
  void addPerson( );

  /*Remove a person*/
  void removePerson( );

  /*Show data through Serial*/
  void showDataSerial( );

  BasicCapacityManagerFrame* getBasicFrame( );

  void setLcd(LcdWrapper* newLcd);

  private:
  /*Basic Frame with basic information about capacity*/
  BasicCapacityManagerFrame basicFrame = BasicCapacityManagerFrame(this);
  LcdWrapper*               lcd;
};

#endif
