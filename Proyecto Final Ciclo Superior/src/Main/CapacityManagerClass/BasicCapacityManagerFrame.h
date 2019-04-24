#ifndef _SIMPLE_CAPACITY_MANAGER_FRAME_H
#define _SIMPLE_CAPACITY_MANAGER_FRAME_H

#include "Arduino.h"
#include "../Common.h"

class CapacityManager;

class BasicCapacityManagerFrame : public LCDFrame
{
public:
    BasicCapacityManagerFrame(CapacityManager *owner, LcdWrapper *myLcd = nullptr, char *frameName = nullptr);

    /*Show data through Lcd*/
    void showLcdData() override;

private:
    CapacityManager *owner;
};

#endif // !_SIMPLE_CAPACITY_MANAGER_FRAME_H
