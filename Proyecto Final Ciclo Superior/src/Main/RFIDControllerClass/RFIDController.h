#ifndef _RFID_CONTROLLER_H
#define _RFID_CONTROLLER_H

#include "../AgendaClass/Agenda.h"
#include "../Common.h"
#include "Arduino.h"
#include "MFRC522.h"
#include "SPI.h"

class RFIDController : public EventManager, public AbstractSensor {

public:
  RFIDController(Agenda *myAgenda, TimeManager *timeManager, Timer *checkTimer,
                 Timer *standByTimer);

  void run();
  void setup() override;
  bool read() override;
  bool Read(Contact *list, uint8_t size);

  Agenda *getAgenda();

private:
  MFRC522 mfrc522 = MFRC522(RFID_SDA, RFID_RST);
  Agenda *agenda;
  char Access_list[2][15];
};

#endif
