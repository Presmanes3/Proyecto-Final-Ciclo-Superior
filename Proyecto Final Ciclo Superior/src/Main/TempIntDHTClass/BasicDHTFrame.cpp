#include "BasicDHTFrame.h"
#include "TempInt_DHT.h"
#include "../LCDWrapper/LCDWrapper.h"

BasicDHTFrame::BasicDHTFrame(DHT_S *owner, LcdWrapper *myLcd, char *frameName) : LCDFrame(myLcd, frameName)
{
    this->owner = owner;
}

void BasicDHTFrame::showLcdData()
{
    this->lcd->setCursor(0, 0);
    this->lcd->print("  DHT22 Data");
    this->lcd->setCursor(0, 1);
    this->lcd->print("T:");
    this->lcd->print(this->owner->getTemperature());
    this->lcd->setCursor(7, 1);
    this->lcd->print("H: ");
    this->lcd->print(this->owner->getHumidity());
}