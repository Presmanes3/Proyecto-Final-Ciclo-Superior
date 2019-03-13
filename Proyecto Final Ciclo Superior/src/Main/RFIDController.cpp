#include "RFIDController.h"

RFIDController::RFIDController() {}

void RFIDController::Setup(bool debug) {
  if (debug) {
    Serial.println(F("===== Iniciando Lector RFID ====="));
  }
  SPI.begin();        // Initiate  SPI bus
  mfrc522.PCD_Init(); // Initiate MFRC522
}

bool RFIDController::Read(AGENDA::Contacto *list, uint8_t contact_list_size,
                          bool debug) {
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
    /*if (debug) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
  }*/

    UID.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    UID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  /* if (debug) {
     Serial.println();
 }*/
  UID.toUpperCase();
  for (uint8_t index = 0; index < contact_list_size; index++) {
    /*Serial.print(F("Contact "));
    Serial.print(index);
    Serial.print(F(" ID : "));
    Serial.println(list[index].ID);*/
    if (UID.substring(1) == String(list[index].ID)) {
      if (debug) {
        Serial.println(F("===== Mostrando Informacion Contacto ====="));
        AGENDA::Print_contact(list[index]);
      }
      return true;
    }
  }

  return false;
}
