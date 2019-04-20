#ifndef _SENSOR_H_
#define _SENSOR_H_

#include "Arduino.h"

class AbstractSensor {
public:
  AbstractSensor();
  ~AbstractSensor();

  virtual bool read(bool debug = false) = 0;
  virtual bool setup(bool debug = false) = 0;
};

#endif // _SENSOR_H_
