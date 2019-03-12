#include "Equipo.h"

uint16_t EQUIPO::num_serie = 0;
char EQUIPO::name[25] = "";

void EQUIPO::Setup(bool debug) {
  EQUIPO::num_serie = EQUIP_SERIAL_NUMBER;
  snprintf(EQUIPO::name, 25, "%s", EQUIP_NAME);
  if (debug)
    EQUIPO::Print_data();
}
void EQUIPO::Print_data() {
  char buff[100];
  snprintf(buff, 100, "Equipo %d : %s\nLocalizacion %s", EQUIPO::num_serie,
           EQUIPO::name, EQUIP_LOCATION);
  Serial.println(buff);
}
