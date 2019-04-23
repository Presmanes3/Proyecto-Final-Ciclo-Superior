#include "SimpleCapacityManagerFrame.h"
#include "Capacity.h"
#include "../LCDWrapper/LCDWrapper.h"

SimpleCapacityManagerFrame::SimpleCapacityManagerFrame(CapacityManager *owner, LcdWrapper *myLcd = nullptr, char *frameName = nullptr) : LCDFrame(myLcd, frameName)
{
    this->owner = owner;
}

void SimpleCapacityManagerFrame::showLcdData()
{
    this->lcd->setCursor(0, 0);
    this->lcd->print("Inside: ");
    this->lcd->print(this->owner->currentCustomersIn);
    this->lcd->setCursor(0, 1);
    this->lcd->print("Max: ");
    this->lcd->print(this->owner->maxCapacity);
}