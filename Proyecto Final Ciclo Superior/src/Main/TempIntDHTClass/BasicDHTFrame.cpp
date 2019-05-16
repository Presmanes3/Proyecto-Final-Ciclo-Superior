#include "CustomDHTClass.h"
//#include "BasicDHTFrame.h"
#include "../LCDWrapper/LCDWrapper.h"

BasicDHTFrame::BasicDHTFrame(CustomDHTClass* owner, LcdWrapper* myLcd,
                             char* frameName)
    : LCDFrame(myLcd, frameName) {
  this->owner = owner;
}

void BasicDHTFrame::showLcdData( ) {
  this->owner->read( );
  this->lcd->setCursor(0, 0);
  this->lcd->print(F("DHT22 Data"));
  this->lcd->setCursor(0, 1);
  this->lcd->print(F("T:"));
  this->lcd->print(this->owner->getTemperature( ));
  this->lcd->setCursor(8, 1);
  this->lcd->print(F("H:"));
  this->lcd->print(this->owner->getHumidity( ));
}
