#include "../LCDWrapper/LCDWrapper.h"
#include "BasicRFIDFrame.h"
#include "RFIDController.h"

BasicRFIDFrame::BasicRFIDFrame(RFIDController* owner, LcdWrapper* myLcd,
                               char* frameName)
    : LCDFrame(myLcd, frameName) {
  this->owner = owner;
}

void BasicRFIDFrame::showLcdData( ) {
  this->lcd->setCursor(0, 0);
  this->lcd->print(String(this->contact->getName( )));
  this->lcd->setCursor(0, 1);
  this->lcd->print(this->contact->getPermission( ) ? "Allowed" : "Not Allowed");
}
