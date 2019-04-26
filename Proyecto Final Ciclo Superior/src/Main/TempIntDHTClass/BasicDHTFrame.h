#ifndef _BASIC_DHT_FRAME_H_
#define _BASIC_DHT_FRAME_H

#include "Arduino.h"
#include "../Common.h"

class CustomDHTClass;

class BasicDHTFrame : public LCDFrame
{
public:
    /*This class needs a reference to a DHT object, LCD and name are optionals*/
    BasicDHTFrame(CustomDHTClass *owner, LcdWrapper *myLcd = nullptr, char *frameName = nullptr);

    /*Show data through Lcd*/
    void showLcdData() override;

private:
    DHT_S *owner;
};

#endif // !_BASIC_DHT_FRAME_H_