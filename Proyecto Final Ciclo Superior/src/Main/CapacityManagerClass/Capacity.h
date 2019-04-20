#ifndef _AFORO_H_
#define _AFORO_H_

#include "../Common.h"
#include "Arduino.h"

class CapacityManager {
public:
  CapacityManager(uint32_t max_capacity);

  uint32_t max_capacity;
  uint32_t customers_in;

  void Setup(bool debug = false);
  void Add(bool debug = false);
  void Substract(bool debug = false);
  void Show(bool debug = false);
};

#endif
