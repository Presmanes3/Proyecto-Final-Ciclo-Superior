#ifndef _BASIC_DHT_FRAME_H_
#define _BASIC_DHT_FRAME_H

#include "Arduino.h"
#include "../Common.h"

class DHT_S;

class BasicDHTFrame : public LCDFrame
{
public:
    BasicDHTFrame(DHT_S *owner, LcdWrapper *myLcd = nullptr, char *frameName = nullptr);

    /*Show data through Lcd*/
    void showLcdData() override;

private:
    DHT_S *owner;
};

#endif // !_BASIC_DHT_FRAME_H_