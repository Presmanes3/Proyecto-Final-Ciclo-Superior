#ifndef _RFID_CONTROLLER_H
#define _RFID_CONTROLLER_H

#include "../Agenda/Agenda.h"
#include "../Common.h"
#include "Arduino.h"
#include "MFRC522.h"
#include "SPI.h"

class RFIDController {

public:
  RFIDController();

  char Access_list[2][15];

  MFRC522 mfrc522 = MFRC522(RFID_SDA, RFID_RST);

  void Setup(bool debug = false);
  bool Read(AGENDA::Contacto *list, uint8_t contact_list_size,
            bool debug = false);
};

#endif
