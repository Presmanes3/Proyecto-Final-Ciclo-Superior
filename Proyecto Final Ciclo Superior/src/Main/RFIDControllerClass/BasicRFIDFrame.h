#ifndef _BASIC_RFID_FRAME_
#define _BASIC_RFID_FRAME_

#include "../AgendaClass/Agenda.h"
#include "../AgendaClass/Contact.h"
#include "../Common.h"
#include "Arduino.h"

class RFIDController;

class BasicRFIDFrame : public LCDFrame {
  public:
  /*This class needs a reference to a RFIDController object, LCD and name are
   * optionals*/
  BasicRFIDFrame(RFIDController* owner, LcdWrapper* myLcd = nullptr,
                 char* frameName = nullptr);

  /*Show data through Lcd*/
  void showLcdData( ) override;

  Contact* contact;

  protected:
  RFIDController* owner;
};
#endif // !_BASIC_RFID_FRAME_
