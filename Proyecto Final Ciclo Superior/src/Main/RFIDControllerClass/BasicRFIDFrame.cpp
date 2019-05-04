#include "BasicRFIDFrame.h"
#include "RFIDController.h"
#include "../LCDWrapper/LCDWrapper.h"

BasicRFIDFrame::BasicRFIDFrame(RFIDController *owner, LcdWrapper *myLcd, char *frameName) : LCDFrame(myLcd, frameName)
{
    this->owner = owner;
}

void BasicRFIDFrame::showLcdData()
{
    //this->lcd->clear()
    this->lcd->setCursor(0, 0);
    this->lcd->print(this->contact->getName()[0]);
    this->lcd->print(F("."));
    this->lcd->print(this->contact->getSurname());
    this->lcd->setCursor(0, 1);
    this->lcd->print(this->contact->getID());
    this->lcd->print("  ");
    if (this->contact->getPermission())
    {
        this->lcd->print("Allowed");
    }
    else
    {
        this->lcd->print("Not Allo.");
    }
}