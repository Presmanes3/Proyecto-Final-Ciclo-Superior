#include "Timer.h"

Timer::Timer(uint32_t _time, uint32_t _reference, bool _flag) {
  Timer::time = _time;
  Timer::reference = _reference;
  Timer::flag = _flag;
}

void Timer::setTime(uint32_t newTime) { Timer::time = newTime; }
void Timer::setReference(uint32_t newReference) {
  Timer::reference = newReference;
}
void Timer::setFlag(bool newFlag) { Timer::reference = newFlag; }

uint32_t getTime() { return Timer::time; }
uint32_t getReference() { return Timer::reference; }
bool getFlag() { return Timer::flag; }

void Timer::activateFlag() { Timer::flag = true; }
void Timer::deactivateFlag() { Timer::flag = false; }
