#ifndef _TIMER_H_
#define _TIMER_H_

#include "Arduino.h"

/*Class for create basic multi-task on main loop*/
class Timer {
public:
  Timer(uint32_t _time, uint32_t _reference, bool _flag);

  /*===== Setters =====*/
  /*Set the time that must past*/
  void setTime(uint32_t newTime);

  /*Set a new reference in milliseconds*/
  void setReference(uint32_t newReference);

  /*This flag will be used to activate of deactivate the timer*/
  void setFlag(bool newFlag);

/*Update reference automaticly to millis()*/
  void updateReferenceMillis();

  /*===== Getters =====*/
  /*Get the time that must past*/
  uint32_t getTime();

  /*Get the current reference*/
  uint32_t getReference();

  /*Get the flag status*/
  bool getFlag();

  /*=====     =====*/
  /*Set flag to true*/
  void activateFlag();
  
  /*Set flag to false*/
  void deactivateFlag();

private:
  uint32_t time;      // Time that must pass
  uint32_t reference; // Var to compare
  // uint32_t inactiveTime;
  bool flag = true;
};
#endif
