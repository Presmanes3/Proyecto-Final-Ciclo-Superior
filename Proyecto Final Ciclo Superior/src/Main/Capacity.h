#ifndef _AFORO_H_
#define _AFORO_H_

#include "Arduino.h"
#include "Common.h"

class CapacityManager {
public:
  CapacityManager(uint32_t max_capacity);

  uint32_t max_capacity;
  uint32_t customers_in;

  void Setup(bool debug = false);
  void Check_Door(bool debug = false);
  void Show(bool debug = false);
};

#endif
