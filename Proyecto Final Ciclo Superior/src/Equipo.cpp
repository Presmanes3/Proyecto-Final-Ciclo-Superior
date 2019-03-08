#include "Equipo.h"

uint16_t EQUIPO::num_serie = 0;
char EQUIPO::name[25] = "";

void EQUIPO::Setup(bool debug) {
  EQUIPO::num_serie = EQUIP_NUM_SERIE;
  snprintf(EQUIPO::name, 25, "%s", EQUIP_NOMBRE);
  if (debug)
    EQUIPO::Print_data();
}
void EQUIPO::Print_data() {
  char buff[40];
  snprintf(buff, 40, "Equipo %d : %s\n", EQUIPO::num_serie, EQUIPO::name);
  Serial.println(buff);
}
