#include "TimeManager.h"

bool TimeManager::pastMil(Timer &timer) {
  if (millis() - timer.getReference() >= timer.getTime()) {
    timer.setReference(millis());
    return true;
  }
  return false;
}
bool TimeManager::pastSec(Timer &timer) {
  if (millis() - timer.getReference() >= (timer.getTime() * 1000)) {
    timer.setReference(millis());
    return true;
  }
  return false;
}
bool TimeManager::pastMin(Timer &timer) {
  if (millis() - timer.getReference() >= (timer.getTime() * 60000)) {
    timer.setReference(millis());
    return true;
  }
  return false;
}
