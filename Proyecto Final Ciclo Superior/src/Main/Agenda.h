#ifndef _AGENDA_H
#define _AGENDA_H

#include "Arduino.h"
#include "Common.h"

namespace AGENDA {

struct Contacto {
  char ID[15];
  char nombre[15];
  char apellido[15];
  char correo[30];
  char telefono[10];
};

extern Contacto Contacto1;
extern Contacto Contacto2;
extern Contacto Contacto3;
extern Contacto Contacto4;

extern Contacto Contact_List[4];

void Setup(bool debug = false);
void Print_contact(AGENDA::Contacto contact);
void Print_contact_list(AGENDA::Contacto *list, uint8_t size);
void Clear_contact(AGENDA::Contacto &contact);

}; // namespace AGENDA

#endif
