#ifndef _EQUIP_H
#define _EQUIP_H

#include "Arduino.h"
#include "Common.h"

namespace EQUIPO {

extern uint16_t num_serie;
extern char name[25];

void Print_data();
void Setup(bool debug = false);

} // namespace EQUIPO

#endif
