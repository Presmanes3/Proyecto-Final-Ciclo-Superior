#include "EventManager.h"

EventManager::EventManager(TimeManager *timeManager, Timer *checkTimer,
                           Timer *standByTimer) {

  this->timeManager = timeManager;
  this->checkTimer = checkTimer;
  this->standByTimer = standByTimer;
}
