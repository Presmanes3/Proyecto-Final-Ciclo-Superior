#include "BasicProbeFrame.h"
#include "CustomProbeClass.h"
#include "../LCDWrapper/LCDWrapper.h"

BasicProbeFrame::BasicProbeFrame(CustomProbeClass *owner, LcdWrapper *myLcd, char *frameName) : LCDFrame(myLcd, frameName)
{
    this->owner = owner;
}

void BasicProbeFrame::showLcdData()
{
    this->owner->read();
    this->lcd->setCursor(0, 0);
    this->lcd->print(F("Probe 0 "));
    this->lcd->print(this->owner->getTemperatureFromDevice(0));
    this->lcd->print(F("ºC"));
    this->lcd->setCursor(0, 1);
    this->lcd->print(F("Probe 1 "));
    this->lcd->print(this->owner->getTemperatureFromDevice(1));
    this->lcd->print(F("ºC"));
}