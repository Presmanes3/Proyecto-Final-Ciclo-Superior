#ifndef _EQUIP_H
#define _EQUIP_H

#include "../Common.h"
#include "Arduino.h"

class Equip {

public:
  void printSerialData();
  void setup();

  void setID(uint16_t newID);
  uint16_t getID();

  void setName(char *newName);
  char *getName();

  void setLocation(char *newLocation);
  char *getLocation();

private:
  uint16_t ID;
  char name[25];
  char location[30];

}; // namespace EQUIPO

#endif
