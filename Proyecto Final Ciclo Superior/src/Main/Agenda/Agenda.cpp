#include "Agenda.h"

AGENDA::Contacto AGENDA::Contacto1;
AGENDA::Contacto AGENDA::Contacto2;
AGENDA::Contacto AGENDA::Contacto3;
AGENDA::Contacto AGENDA::Contacto4;

AGENDA::Contacto AGENDA::Contact_List[4];

void AGENDA::Setup(bool debug) {

  snprintf(AGENDA::Contacto1.nombre, 15, "%s", CONTACTO1_NOMBRE);
  snprintf(AGENDA::Contacto1.apellido, 15, "%s", CONTACTO1_APELLIDO);
  snprintf(AGENDA::Contacto1.correo, 30, "%s", CONTACTO1_CORREO);
  snprintf(AGENDA::Contacto1.telefono, 10, "%s", CONTACTO1_TELEFONO);
  snprintf(AGENDA::Contacto1.ID, 15, "%s", CONTACTO1_ID);

  snprintf(AGENDA::Contacto2.nombre, 15, "%s", CONTACTO2_NOMBRE);
  snprintf(AGENDA::Contacto2.apellido, 15, "%s", CONTACTO2_APELLIDO);
  snprintf(AGENDA::Contacto2.correo, 30, "%s", CONTACTO2_CORREO);
  snprintf(AGENDA::Contacto2.telefono, 10, "%s", CONTACTO2_TELEFONO);
  snprintf(AGENDA::Contacto2.ID, 15, "%s", CONTACTO2_ID);

  snprintf(AGENDA::Contacto3.nombre, 15, "%s", CONTACTO3_NOMBRE);
  snprintf(AGENDA::Contacto3.apellido, 15, "%s", CONTACTO3_APELLIDO);
  snprintf(AGENDA::Contacto3.correo, 30, "%s", CONTACTO3_CORREO);
  snprintf(AGENDA::Contacto3.telefono, 10, "%s", CONTACTO3_TELEFONO);
  snprintf(AGENDA::Contacto3.ID, 15, "%s", CONTACTO3_ID);

  snprintf(AGENDA::Contacto4.nombre, 15, "%s", CONTACTO4_NOMBRE);
  snprintf(AGENDA::Contacto4.apellido, 15, "%s", CONTACTO4_APELLIDO);
  snprintf(AGENDA::Contacto4.correo, 30, "%s", CONTACTO4_CORREO);
  snprintf(AGENDA::Contacto4.telefono, 10, "%s", CONTACTO4_TELEFONO);
  snprintf(AGENDA::Contacto4.ID, 15, "%s", CONTACTO4_ID);

  AGENDA::Contact_List[0] = AGENDA::Contacto1;
  AGENDA::Contact_List[1] = AGENDA::Contacto2;
  AGENDA::Contact_List[2] = AGENDA::Contacto3;
  AGENDA::Contact_List[3] = AGENDA::Contacto4;

  if (debug) {
    AGENDA::Print_contact_list(AGENDA::Contact_List, 4);
  }
}
void AGENDA::Print_contact(AGENDA::Contacto contact) {
  char buff[50];

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
  Serial.println(buff);
}
void AGENDA::Print_contact_list(AGENDA::Contacto *list, uint8_t size) {
  for (uint8_t index = 0; index < size; index++) {
    AGENDA::Print_contact(list[index]);
  }
}
void AGENDA::Clear_contact(AGENDA::Contacto &contact) {
  memset(contact.nombre, '\0', 15);
  memset(contact.apellido, '\0', 15);
  memset(contact.correo, '\0', 30);
  memset(contact.telefono, '\0', 10);
}
