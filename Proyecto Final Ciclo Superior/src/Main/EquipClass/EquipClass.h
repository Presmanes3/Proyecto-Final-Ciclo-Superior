#ifndef _EQUIP_H
#define _EQUIP_H

#include "../Common.h"
#include "Arduino.h"

/* Basic Equip class*/
class Equip {

public:

  /* Shows data through serial*/
  void printSerialData();

  /* Starts the Equip*/
  void setup();

  /* Sets Equip ID*/
  void setID(uint16_t newID);

  /* Return Equip ID*/
  uint16_t getID();

  /* Sets Equip name*/
  void setName(char *newName);

  /* Return Equip name*/
  char *getName();

  /* Sets Equip location*/
  void setLocation(char *newLocation);

  /* Return Equip location*/
  char *getLocation();

private:
  uint16_t ID;
  char name[25];
  char location[30];

}; // namespace EQUIPO

#endif
