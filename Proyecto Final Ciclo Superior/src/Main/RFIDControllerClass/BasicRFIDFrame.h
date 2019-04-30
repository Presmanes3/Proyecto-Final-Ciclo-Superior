#ifndef _BASIC_RFID_FRAME_
#define _BASIC_RFID_FRAME_

#include "Arduino.h"
#include "../Common.h"
#include "../AgendaClass/Agenda.h"
#include "../AgendaClass/Contact.h"

class RFIDController;

class BasicRFIDFrame : public LCDFrame
{
public:
    /*This class needs a reference to a RFIDController object, LCD and name are optionals*/
    BasicRFIDFrame(RFIDController *owner, LcdWrapper *myLcd = nullptr, char *frameName = nullptr);

    /*Show data through Lcd*/
    void showLcdData() override;

protected:
    RFIDController *owner;
    Contact *contact;
};
#endif // !_BASIC_RFID_FRAME_