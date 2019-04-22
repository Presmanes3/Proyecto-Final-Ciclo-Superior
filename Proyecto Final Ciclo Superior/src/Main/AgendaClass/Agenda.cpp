#include "Agenda.h"

Agenda::Agenda() {
  this->size = AGENDA_SIZE;
  // printContactList(this->ContactList, this->size);
}

void Agenda::Setup() {

#if SERIAL_DEBUG
  printContactList(Agenda::ContactList, this->size);
#endif
}
void Agenda::printContact(Contact contact) { contact.showSerialData(); }
void Agenda::printContactList(Contact *list, uint8_t size) {
  for (uint8_t index = 0; index < size; index++) {
    list[index].showSerialData();
  }
}
void Agenda::clearContact(Contact &contact) { contact.clear(); }

Contact *Agenda::getContactList() { return this->ContactList; }
