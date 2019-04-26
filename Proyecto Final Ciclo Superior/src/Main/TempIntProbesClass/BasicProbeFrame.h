#ifndef _BASIC_PROBE_FRAME_H_
#define _BASIC_PROBE_FRAME_H_

#include "Arduino.h"
#include "../Common.h"

class CustomProbeClass;

class BasicProbeFrame : public LCDFrame
{
public:
    /*This class needs a reference to a Probe object, LCD and name are optionals*/
    BasicProbeFrame(CustomProbeClass *owner, LcdWrapper *myLcd = nullptr, char *frameName = nullptr);

    /*Show data through Lcd*/
    void showLcdData() override;

private:
    PROBE *owner;
};

#endif // !_BASIC_PROBE_FRAME_H_