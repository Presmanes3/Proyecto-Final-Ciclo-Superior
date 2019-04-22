#include "RFIDController.h"

RFIDController::RFIDController(Agenda *agenda, TimeManager *timeManager,
                               Timer *checkTimer, Timer *standByTimer)
    : EventManager(timeManager, checkTimer, standByTimer) {
  this->agenda = agenda;

  this->checkTimer->activateFlag();
  this->standByTimer->deactivateFlag();
}

void RFIDController::setup() {
#if IN_OUT_RFID_DEBUG
  Serial.println(F("===== Iniciando Lector RFID ====="));
#endif
  SPI.begin();        // Initiate  SPI bus
  mfrc522.PCD_Init(); // Initiate MFRC522
}

bool RFIDController::Read(Contact *list, uint8_t size) {
  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return false;
  }
  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return false;
  }

  String UID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    /*#if IN_OUT_RFID_DEBUG
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      #endif
  }*/

    UID.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    UID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  /* #if IN_OUT_RFID_DEBUG
     Serial.println();
     #endif
 }*/
  UID.toUpperCase();
  for (uint8_t index = 0; index < size; index++) {
    /*
#if IN_OUT_RFID_DEBUG
    Serial.print(F("Contact "));
    Serial.print(index);
    Serial.print(F(" ID : "));
    Serial.println(list[index].ID);

    #endif*/
    if (UID.substring(1) == String(list[index].getID())) {
#if IN_OUT_RFID_DEBUG
      Serial.println(F("===== Mostrando Informacion Contacto ====="));
      this->agenda->printContact(list[index]);
#endif
      return true;
    }
  }

  return false;
}

Agenda *RFIDController::getAgenda() { return this->agenda; }

void RFIDController::run() {
  if (this->checkTimer->getFlag()) {
    if (this->timeManager->pastMil(*this->checkTimer)) {
      this->Read(this->agenda->ContactList, this->agenda->size);

      this->checkTimer->deactivateFlag();
      this->standByTimer->activateFlag();
    }
  }

  if (this->standByTimer->getFlag()) {
    if (this->timeManager->pastMil(*this->standByTimer)) {

      this->standByTimer->deactivateFlag();
      this->checkTimer->activateFlag();
    }
  }
}

bool RFIDController::read() { return false; }
