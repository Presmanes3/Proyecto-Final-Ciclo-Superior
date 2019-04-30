#include "Timer.h"

Timer::Timer(uint32_t _time, uint32_t _reference, bool _flag) {
  this->time = _time;
  // this->time = _inactiveTime;
  this->reference = _reference;
  this->flag = _flag;
}

/*===== Setters =====*/
void Timer::setTime(uint32_t newTime) { this->time = newTime; }
/*void Timer::setInactiveTime(uint32_t newInactiveTime) {
  this->inactiveTime = newInactiveTime;
}*/
void Timer::setReference(uint32_t newReference) {
  this->reference = newReference;
}
void Timer::setFlag(bool newFlag) { this->reference = newFlag; }

/*===== Getters =====*/
uint32_t Timer::getTime() { return this->time; }
/*uint32_t Timer::getInactiveTime() { return this->inactiveTime; }*/
uint32_t Timer::getReference() { return this->reference; }
bool Timer::getFlag() { return this->flag; }

/*=====     =====*/
void Timer::activateFlag() { this->flag = true; }
void Timer::deactivateFlag() { this->flag = false; }

void Timer::updateReference(){this->reference = millis();}