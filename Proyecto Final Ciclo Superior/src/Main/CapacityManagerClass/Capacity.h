#ifndef _AFORO_H_
#define _AFORO_H_

#include "../Common.h"
#include "Arduino.h"
#include "SimpleCapacityManagerFrame.h"

class CapacityManager
{
public:
  CapacityManager(uint32_t max_capacity, LcdWrapper *myLcd = nullptr, char *frameName = nullptr);

  uint32_t maxCapacity;
  uint32_t currentCustomersIn;

  /*This function must be called at the setup*/
  void setup();

  /*Adds a person*/
  void addPerson();

  /*Remove a person*/
  void removePerson();

  /*Show data through Serial*/
  void showDataSerial();

private:
  /*Basic Frame with basic information about capacity*/
  SimpleCapacityManagerFrame simpleFrame = SimpleCapacityManagerFrame(this);
};

#endif
