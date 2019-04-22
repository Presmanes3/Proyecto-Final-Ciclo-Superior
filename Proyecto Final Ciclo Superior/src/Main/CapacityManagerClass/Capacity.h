#ifndef _AFORO_H_
#define _AFORO_H_

#include "../Common.h"
#include "Arduino.h"

class CapacityManager {
public:
  CapacityManager(uint32_t max_capacity);

  uint32_t maxCapacity;
  uint32_t currentCustomersIn;

  void Setup();
  void Add();
  void Substract();
  void Show();
};

#endif
