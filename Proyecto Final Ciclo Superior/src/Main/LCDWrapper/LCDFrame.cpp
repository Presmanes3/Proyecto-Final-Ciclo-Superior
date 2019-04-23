#include "LCDFrame.h"

LCDFrame::LCDFrame(LcdWrapper *myLcd, char *frameName)
{
  this->lcd = myLcd;
  snprintf(this->name, 15, "%s", frameName);
}

void LCDFrame::setName(char *newName) { snprintf(this->name, 15, "%s", newName); }
char *LCDFrame::getName() { return this->name; }
