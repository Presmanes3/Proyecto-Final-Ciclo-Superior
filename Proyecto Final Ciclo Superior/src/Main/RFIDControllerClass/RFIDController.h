#ifndef _RFID_CONTROLLER_H
#define _RFID_CONTROLLER_H

#include "../Agenda/Agenda.h"
#include "../Common.h"
#include "Arduino.h"
#include "MFRC522.h"
#include "SPI.h"

class RFIDController {

public:
  RFIDController(Agenda *myAgenda);

  char Access_list[2][15];

  MFRC522 mfrc522 = MFRC522(RFID_SDA, RFID_RST);

  void Setup(bool debug = false);
  bool Read(Contact *list, uint8_t size, bool debug = false);

  Agenda *getAgenda();

private:
  Agenda *myAgenda;
};

#endif
