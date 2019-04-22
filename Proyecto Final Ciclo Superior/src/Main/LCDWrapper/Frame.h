#ifndef _FRAME_H_
#define _FRAME_H_

#include "Arduino.h"

class LcdWrapper;

class Frame {
public:
  Frame(LcdWrapper *myLcd, char *frameName);

  virtual void show() = 0;
  char *getName();
  void setName(char *newName);

private:
  LcdWrapper *lcd;
  char name[15];
};

#endif
