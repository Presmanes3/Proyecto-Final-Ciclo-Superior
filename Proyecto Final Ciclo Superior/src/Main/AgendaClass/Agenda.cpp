#include "Agenda.h"

Agenda::Agenda( ) { this->size = AGENDA_SIZE; }

void Agenda::Setup( ) {

#if SERIAL_DEBUG
  Serial.println("=========== Mostrando Datos Contactos ===========\n");
  this->printContactList(this->ContactList, this->size);
  Serial.println(SERIAL_SPLITTER);
#endif
}
void Agenda::printContact(Contact contact) { contact.showSerialData( ); }
void Agenda::printContactList(Contact* list, uint8_t size) {
  for(uint8_t index = 0; index < size; index++) {
    list[index].showSerialData( );
    Serial.println( );
  }
}
void Agenda::clearContact(Contact& contact) { contact.clear( ); }

Contact* Agenda::getContactList( ) { return this->ContactList; }
