#ifndef _RFID_CONTROLLER_H
#define _RFID_CONTROLLER_H

#include "../AgendaClass/Agenda.h"
#include "../Common.h"
#include "Arduino.h"
#include "MFRC522.h"
#include "SPI.h"
#include "BasicRFIDFrame.h"

class RFIDController : public EventManager, public AbstractSensor
{

public:
  RFIDController(Agenda *myAgenda, TimeManager *timeManager, Timer *checkTimer, Timer *standByTimer, LcdWrapper *myLcd = nullptr, char *frameName = nullptr);

  /*This is the update function*/
  void run();

  /*This function must be called at the begin of the program*/
  void setup() override;

  /*This function does nothing*/
  bool read() override;

  /*This function reads the RFID sensor and waits for someone
who is in the contact list, if it's in the contact list
then shows the information through serial and sends to the 
Lcd Frame the contact as pointer*/
  bool Read(Contact *list, uint8_t size);

  /*Return a pointer to a Contact list*/
  Agenda *getAgenda();

protected:
  BasicRFIDFrame basicFrame = BasicRFIDFrame(this);
  MFRC522 mfrc522 = MFRC522(RFID_SDA, RFID_RST);
  Agenda *agenda;

  char Access_list[2][15];
};

#endif
