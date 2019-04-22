#include "Frame.h"

Frame::Frame(LcdWrapper *myLcd, char *frameName) {
  this->lcd = myLcd;
  snprintf(this->name, 15, "%s", frameName);
}

void Frame::setName(char *newName) { snprintf(this->name, 15, "%s", newName); }
char *Frame::getName() { return this->name; }
