#include "LCDFrame.h"

LCDFrame::LCDFrame(LcdWrapper *myLcd, char *frameName)
{
  this->lcd = myLcd;
  snprintf(this->name, 15, "%s", frameName);
}

void LCDFrame::setName(char *newName) { snprintf(this->name, 15, "%s", newName); }
char *LCDFrame::getName() { return this->name; }

void LCDFrame::activateFlag()
{
  this->flag = true;
}
void LCDFrame::deActivateFlag()
{
  this->flag = false;
}
bool LCDFrame::isActivated()
{
  return this->flag;
}

void LCDFrame::setLcd(LcdWrapper *lcd){
  this->lcd = lcd;
}

LcdWrapper* LCDFrame::getLcd(){
  return this->lcd;
}