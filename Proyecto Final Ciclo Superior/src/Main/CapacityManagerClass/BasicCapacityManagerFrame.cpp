#include "BasicCapacityManagerFrame.h"
#include "Capacity.h"
#include "../LCDWrapper/LCDWrapper.h"

BasicCapacityManagerFrame::BasicCapacityManagerFrame(CapacityManager *owner, LcdWrapper *myLcd, char *frameName) : LCDFrame(myLcd, frameName)
{
    this->owner = owner;
}

void BasicCapacityManagerFrame::showLcdData()
{
    this->lcd->setCursor(0, 0);
    this->lcd->print("Inside: ");
    this->lcd->print(this->owner->currentCustomersIn);
    this->lcd->setCursor(0, 1);
    this->lcd->print("Max: ");
    this->lcd->print(this->owner->maxCapacity);
}