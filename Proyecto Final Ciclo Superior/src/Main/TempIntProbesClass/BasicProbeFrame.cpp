#include "../LCDWrapper/LCDWrapper.h"
#include "BasicProbeFrame.h"
#include "CustomProbeClass.h"

BasicProbeFrame::BasicProbeFrame(CustomProbeClass* owner, LcdWrapper* myLcd,
                                 char* frameName)
    : LCDFrame(myLcd, frameName) {
  this->owner = owner;
}

void BasicProbeFrame::showLcdData( ) {
  this->owner->read( );
  this->lcd->setCursor(0, 0);
  this->lcd->print(F("Probe 0 "));
  this->lcd->print(this->owner->getTemperatureFromDevice(0), 2);
  this->lcd->print(F(" C"));
  this->lcd->setCursor(0, 1);
  this->lcd->print(F("Probe 1 "));
  this->lcd->print(this->owner->getTemperatureFromDevice(1), 2);
  this->lcd->print(F(" C"));
}
