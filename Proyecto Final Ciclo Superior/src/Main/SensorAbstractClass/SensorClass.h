#ifndef _SENSOR_H_
#define _SENSOR_H_

#include "Arduino.h"

class AbstractSensor {
public:
  virtual bool read(bool debug = false) = 0;
  virtual void setup(bool debug = false) = 0;
};

#endif // _SENSOR_H_
