#ifndef _AGENDA_H
#define _AGENDA_H

#include "../Common.h"
#include "Arduino.h"
#include "Contact.h"

#define NUM_CONTACTS 4

class Agenda {
public:
  Agenda();

  Contact *ContactList;
  uint16_t size;

  /*
  extern Contacto Contacto1;
  extern Contacto Contacto2;
  extern Contacto Contacto3;
  extern Contacto Contacto4;

  extern Contacto Contact_List[4];
  */
  void Setup(bool debug = false);
  void printContact(Contact contact);
  void printContactList(Contact *list, uint8_t size);
  void clearContact(Contact &contact);
  Contact *getContactList();

protected:
  Contact Contacto1 =
      Contact((char *)CONTACTO1_ID, (char *)CONTACTO1_NOMBRE,
              (char *)CONTACTO1_APELLIDO, (char *)CONTACTO1_CORREO,
              (char *)CONTACTO1_TELEFONO);
  Contact Contacto2 =
      Contact((char *)CONTACTO2_ID, (char *)CONTACTO2_NOMBRE,
              (char *)CONTACTO2_APELLIDO, (char *)CONTACTO2_CORREO,
              (char *)CONTACTO2_TELEFONO);
  Contact Contacto3 =
      Contact((char *)CONTACTO3_ID, (char *)CONTACTO3_NOMBRE,
              (char *)CONTACTO3_APELLIDO, (char *)CONTACTO3_CORREO,
              (char *)CONTACTO3_TELEFONO);
  Contact Contacto4 =
      Contact((char *)CONTACTO4_ID, (char *)CONTACTO4_NOMBRE,
              (char *)CONTACTO4_APELLIDO, (char *)CONTACTO4_CORREO,
              (char *)CONTACTO4_TELEFONO);

}; // namespace AGENDA

#endif
