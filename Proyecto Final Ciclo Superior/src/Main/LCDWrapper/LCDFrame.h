#ifndef _FRAME_H_
#define _FRAME_H_

#include "Arduino.h"

class LcdWrapper;

class LCDFrame
{
public:
  /*This class needs an Lcd and a name as parameters*/
  LCDFrame(LcdWrapper *myLcd = nullptr, char *frameName = nullptr);

  /*Abstract functions to show what we want to show on Lcd*/
  virtual void showLcdData() = 0;

  /*Returns Frame name*/
  char *getName();

  /*Changes Frame name*/
  void setName(char *newName);

  /*Set flag to true*/
  void activateFlag();

  /*Set flag to false*/
  void deActivateFlag();

  /*Returns true if flag is true*/
  bool isActivated();

protected:
  /*Pointer to Lcd*/
  LcdWrapper *lcd;

  /*Frame's name*/
  char name[15];

  bool flag;
};

#endif
