#ifndef _SENSOR_H_
#define _SENSOR_H_

#include "Arduino.h"

class AbstractSensor {
public:
  virtual bool read() = 0;
  virtual void setup() = 0;
};

#endif // _SENSOR_H_
