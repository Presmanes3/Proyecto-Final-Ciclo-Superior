#ifndef _AGENDA_H
#define _AGENDA_H

#include "../Common.h"
#include "Arduino.h"
#include "Contact.h"

#define NUM_CONTACTS 4

class Agenda {
  public:
  Agenda( );

  /*
  extern Contacto Contacto1;
  extern Contacto Contacto2;
  extern Contacto Contacto3;
  extern Contacto Contacto4;

  extern Contacto Contact_List[4];
  */

  /* Starts the Agenda*/
  void Setup( );

  /* Print a contact from agenda through Serial*/
  void printContact(Contact contact);

  /* Print a contact list from Agenda through Serial*/
  void printContactList(Contact* list, uint8_t size);

  /* Sets all the values of a contact to 0*/
  void clearContact(Contact& contact);

  /* Returns the Agenda contact list*/
  Contact* getContactList( );

  Contact Contacto1 =
      Contact(CONTACTO1_ID, CONTACTO1_NOMBRE, CONTACTO1_APELLIDO,
              CONTACTO1_CORREO, CONTACTO1_TELEFONO);
  Contact Contacto2 =
      Contact(CONTACTO2_ID, CONTACTO2_NOMBRE, CONTACTO2_APELLIDO,
              CONTACTO2_CORREO, CONTACTO2_TELEFONO);
  Contact Contacto3 =
      Contact(CONTACTO3_ID, CONTACTO3_NOMBRE, CONTACTO3_APELLIDO,
              CONTACTO3_CORREO, CONTACTO3_TELEFONO);
  Contact Contacto4 =
      Contact(CONTACTO4_ID, CONTACTO4_NOMBRE, CONTACTO4_APELLIDO,
              CONTACTO4_CORREO, CONTACTO4_TELEFONO);

  Contact  ContactList[4] = {Contacto1, Contacto2, Contacto3, Contacto4};
  uint16_t size;

}; // namespace AGENDA

#endif
