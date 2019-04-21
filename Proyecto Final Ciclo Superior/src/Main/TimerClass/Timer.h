#ifndef _TIMER_H_
#define _TIMER_H_

#include "Arduino.h"

class Timer {
public:
  Timer(uint32_t _time, uint32_t _reference, bool _flag);

  /*===== Setters =====*/
  void setTime(uint32_t newTime);
  // void setInactiveTime(uint32_t newInactiveTime);
  void setReference(uint32_t newReference);
  void setFlag(bool newFlag);

  /*===== Getters =====*/
  uint32_t getTime();
  // uint32_t getInactiveTime();
  uint32_t getReference();
  bool getFlag();

  /*=====     =====*/
  void activateFlag();
  void deactivateFlag();

private:
  uint32_t time;      // Time that must pass
  uint32_t reference; // Var to compare
  // uint32_t inactiveTime;
  bool flag = true;
};
#endif
