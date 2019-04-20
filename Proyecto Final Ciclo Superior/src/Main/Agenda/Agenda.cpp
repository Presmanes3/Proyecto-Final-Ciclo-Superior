#include "Agenda.h"
/*
Contact Agenda::Contacto1;
Contact Agenda::Contacto2;
Contact Agenda::Contacto3;
Contact Agenda::Contacto4;

Contact Agenda::ContactList[4];
*/

Agenda::Agenda() {
  // Agenda::Print_contact_list(Agenda::Contact_List, 4);
  printContactList(Agenda::ContactList, NUM_CONTACTS);
}
void Agenda::Setup(bool debug) {
  /*
    snprintf(Agenda::Contacto1.nombre, 15, "%s", CONTACTO1_NOMBRE);
    snprintf(Agenda::Contacto1.apellido, 15, "%s", CONTACTO1_APELLIDO);
    snprintf(Agenda::Contacto1.correo, 30, "%s", CONTACTO1_CORREO);
    snprintf(Agenda::Contacto1.telefono, 10, "%s", CONTACTO1_TELEFONO);
    snprintf(Agenda::Contacto1.ID, 15, "%s", CONTACTO1_ID);

    snprintf(Agenda::Contacto2.nombre, 15, "%s", CONTACTO2_NOMBRE);
    snprintf(Agenda::Contacto2.apellido, 15, "%s", CONTACTO2_APELLIDO);
    snprintf(Agenda::Contacto2.correo, 30, "%s", CONTACTO2_CORREO);
    snprintf(Agenda::Contacto2.telefono, 10, "%s", CONTACTO2_TELEFONO);
    snprintf(Agenda::Contacto2.ID, 15, "%s", CONTACTO2_ID);

    snprintf(Agenda::Contacto3.nombre, 15, "%s", CONTACTO3_NOMBRE);
    snprintf(Agenda::Contacto3.apellido, 15, "%s", CONTACTO3_APELLIDO);
    snprintf(Agenda::Contacto3.correo, 30, "%s", CONTACTO3_CORREO);
    snprintf(Agenda::Contacto3.telefono, 10, "%s", CONTACTO3_TELEFONO);
    snprintf(Agenda::Contacto3.ID, 15, "%s", CONTACTO3_ID);

    snprintf(Agenda::Contacto4.nombre, 15, "%s", CONTACTO4_NOMBRE);
    snprintf(Agenda::Contacto4.apellido, 15, "%s", CONTACTO4_APELLIDO);
    snprintf(Agenda::Contacto4.correo, 30, "%s", CONTACTO4_CORREO);
    snprintf(Agenda::Contacto4.telefono, 10, "%s", CONTACTO4_TELEFONO);
    snprintf(Agenda::Contacto4.ID, 15, "%s", CONTACTO4_ID);

    Agenda::Contact_List[0] = Agenda::Contacto1;
    Agenda::Contact_List[1] = Agenda::Contacto2;
    Agenda::Contact_List[2] = Agenda::Contacto3;
    Agenda::Contact_List[3] = Agenda::Contacto4;
  */
  /*
    Agenda::Contacto1 =
        Contact(CONTACTO1_ID, CONTACTO1_NOMBRE, CONTACTO1_APELLIDO,
                CONTACTO1_CORREO, CONTACTO1_TELEFONO);
    Agenda::Contacto2 =
        Contact(CONTACTO2_ID, CONTACTO2_NOMBRE, CONTACTO2_APELLIDO,
                CONTACTO2_CORREO, CONTACTO2_TELEFONO);
    Agenda::Contacto3 =
        Contact(CONTACTO3_ID, CONTACTO3_NOMBRE, CONTACTO3_APELLIDO,
                CONTACTO3_CORREO, CONTACTO3_TELEFONO);
    Agenda::Contacto4 =
        Contact(CONTACTO4_ID, CONTACTO4_NOMBRE, CONTACTO4_APELLIDO,
                CONTACTO4_CORREO, CONTACTO4_TELEFONO);

  ContactList[0] = Agenda::Contacto1;
  ContactList[1] = Agenda::Contacto2;
  ContactList[2] = Agenda::Contacto3;
  ContactList[3] = Agenda::Contacto4;
*/
  if (debug) {
    // Agenda::Print_contact_list(Agenda::Contact_List, 4);
    printContactList(Agenda::ContactList, NUM_CONTACTS);
  }
}
void Agenda::printContact(Contact contact) {
  /*char buff[50];

  memset(buff, '\0', 50);
  snprintf(buff, 50, "Contacto : %s %s\n", contact.nombre, contact.apellido);
  Serial.print(buff);

  memset(buff, '\0', 50);
  snprintf(buff, 50, "ID : %s\n", contact.ID);
  Serial.print(buff);

  memset(buff, '\0', 50);
  snprintf(buff, 50, "Correo : %s\n", contact.correo);
  Serial.print(buff);

  memset(buff, '\0', 50);
  snprintf(buff, 50, "Telefono : %s\n", contact.telefono);
  Serial.println(buff);*/

  contact.showSerialData();
}
void Agenda::printContactList(Contact *list, uint8_t size) {
  for (uint8_t index = 0; index < size; index++) {
    list[index].showSerialData();
  }
}
void Agenda::clearContact(Contact &contact) { contact.clear(); }
/*
Contact *getContactList() { return Agenda::ContactList; }
*/
