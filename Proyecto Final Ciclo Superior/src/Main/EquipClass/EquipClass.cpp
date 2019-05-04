#include "EquipClass.h"

void Equip::setup()
{
  this->ID = EQUIP_SERIAL_NUMBER;

  snprintf(this->location, 30, "%s", EQUIP_LOCATION);
  snprintf(this->name, 25, "%s", EQUIP_NAME);

#if MAIN_DEBUG
  this->printSerialData();
#endif
}
void Equip::printSerialData()
{
#if MAIN_DEBUG
  Serial.println(F("========== Mostrandos Informacion Equipo =========="));
  char buff[100];
  snprintf(buff, 100, "Equipo %d : %s\n%sLocalizacion : %s", this->ID, this->name,
           SERIAL_TAB, this->location);
  Serial.print(F(SERIAL_TAB));
  Serial.println(buff);
#endif
}

void Equip::setID(uint16_t newID) { this->ID = newID; }
uint16_t Equip::getID() { return this->ID; }

void Equip::setName(char *newName) { snprintf(this->name, 25, "%s", newName); }
char *Equip::getName() { return this->name; }

void Equip::setLocation(char *newLocation)
{
  snprintf(this->location, 30, "%s", newLocation);
}
char *Equip::getLocation() { return this->location; }
