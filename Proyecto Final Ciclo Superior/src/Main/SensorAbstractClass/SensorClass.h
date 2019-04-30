#ifndef _SENSOR_H_
#define _SENSOR_H_

#include "Arduino.h"

/*This class must be improved during the time in order to create more precise and useful sensors*/

/*Abstract class for creating sensors*/
class AbstractSensor {
public:

  /* Reads the sensor and returns a bool*/
  virtual bool read() = 0;

  /* Starts the sensor*/
  virtual void setup() = 0;
};

#endif // _SENSOR_H_
