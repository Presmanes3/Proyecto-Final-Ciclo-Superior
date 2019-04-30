#ifndef _BASIC_PROBE_FRAME_H_
#define _BASIC_PROBE_FRAME_H_

#include "Arduino.h"
#include "../Common.h"

class CustomProbeClass;

/*Class based on LCDFrame to create Basic Probe GUI with a LCD*/
class BasicProbeFrame : public LCDFrame
{
public:
    /*This class needs a reference to a Probe object, LCD and name are optionals*/
    BasicProbeFrame(CustomProbeClass *owner, LcdWrapper *myLcd = nullptr, char *frameName = nullptr);

    /*Show data through Lcd*/
    void showLcdData() override;

private:
    /* This class will use owner to get it's information */
    CustomProbeClass *owner;
};

#endif // !_BASIC_PROBE_FRAME_H_