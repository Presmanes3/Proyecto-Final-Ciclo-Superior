#include "BasicProbeFrame.h"
#include "CustomProbeClass.h"
#include "../LCDWrapper/LCDWrapper.h"

BasicProbeFrame::BasicProbeFrame(CustomProbeClass *owner, LcdWrapper *myLcd, char *frameName) : LCDFrame(myLcd, frameName)
{
    this->owner = owner;
}

void BasicProbeFrame::showLcdData()
{ /*
    this->lcd->setCursor(0, 0);
    this->lcd->print(F("DHT22 Data"));
    this->lcd->setCursor(0, 1);
    this->lcd->print(F("T:"));
    this->lcd->print(this->owner->getTemperature());
    this->lcd->setCursor(7, 1);
    this->lcd->print(F("H: "));
    this->lcd->print(this->owner->getHumidity());*/
}