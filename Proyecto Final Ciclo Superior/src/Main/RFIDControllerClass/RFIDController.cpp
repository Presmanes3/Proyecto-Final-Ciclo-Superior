#include "RFIDController.h"

RFIDController::RFIDController(Agenda* agenda, TimeManager* timeManager,
                               Timer* checkTimer, Timer* standByTimer,
                               LcdWrapper* myLcd, char* frameName)
    : EventManager(timeManager, checkTimer, standByTimer) {

  this->agenda = agenda;

  this->basicFrame = BasicRFIDFrame(this, myLcd, frameName);
  this->lcd        = myLcd;

  this->checkTimer->activateFlag( );
  this->standByTimer->deactivateFlag( );

  /*Contacts 1 and 3 are allowed and Contacts 2 and 4 are not allowed*/
}

void RFIDController::setup( ) {
#if IN_OUT_RFID_DEBUG
  Serial.println(F("============= Iniciando Lector RFID ============="));
#endif
  SPI.begin( );              // Initiate  SPI bus
  this->mfrc522.PCD_Init( ); // Initiate MFRC522

  this->agenda->Contacto1.setPermission(true);
  this->agenda->Contacto3.setPermission(true);

  this->agenda->Contacto2.setPermission(false);
  this->agenda->Contacto4.setPermission(false);

#if IN_OUT_RFID_DEBUG
  Serial.println(F(SERIAL_SPLITTER));
#endif
}
/*This function reads the RFID sensor and waits for someone
who is in the contact list, if it's in the contact list
then shows the information through serial and sends to the
Lcd Frame the contact as pointer*/
bool RFIDController::Read(Contact* list, uint8_t size) {
  // Look for new cards
  if(!mfrc522.PICC_IsNewCardPresent( )) { return false; }
  // Select one of the cards
  if(!mfrc522.PICC_ReadCardSerial( )) { return false; }

  String UID = "";
  for(byte i = 0; i < mfrc522.uid.size; i++) {

    UID.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    UID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
#if IN_OUT_RFID_DEBUG
  Serial.print(SERIAL_DEBUG_TAG);
  for(byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println( );
#endif

  UID.toUpperCase( );
  for(uint8_t index = 0; index < size; index++) {
    Contact currentContact = list[index];

#if IN_OUT_RFID_DEBUG
    Serial.print(F(SERIAL_DEBUG_TAG));
    Serial.print(F("Contact "));
    Serial.print(index);
    Serial.print(F(" ID : "));
    Serial.println(currentContact.getID( ));

    Serial.print(F(SERIAL_DEBUG_TAG));
    Serial.print("UID substring: ");
    Serial.println(UID.substring(1));
    Serial.println( );
#endif

    /*If the contact is allowed print the info and send to lcd*/

    if(UID.substring(1) == String(currentContact.getID( ))) {
      this->basicFrame.contact = &currentContact;
#if IN_OUT_RFID_SERIAL_GUI
      Serial.println(F("=========== Mostrando Datos Contacto ==========="));
      this->agenda->printContact(list[index]);
      Serial.println(F(SERIAL_SPLITTER));
      Serial.println( );
#endif
      if(currentContact.getPermission( )) { return true; }
    }
  }
  return false;
}

Agenda* RFIDController::getAgenda( ) { return this->agenda; }

bool RFIDController::run( ) {
  if(this->checkTimer->getFlag( )) {
    if(this->timeManager->pastMil(*this->checkTimer)) {
      if(this->Read(this->agenda->ContactList, this->agenda->size)) {
#if IN_OUT_RFID_LCD_DEBUG
        this->lcd->clear( );
        this->lcd->changeFrame(&this->basicFrame);
#endif

        this->checkTimer->deactivateFlag( );
        this->standByTimer->activateFlag( );

        this->standByTimer->updateReferenceMillis( );
        return true;
      }
    }
  }

  if(this->standByTimer->getFlag( )) {
    if(this->timeManager->pastSec(*this->standByTimer)) {

      this->lcd->clear( );
      this->lcd->changeFrame(this->lcd->getDefaultFrame( ));

      this->standByTimer->deactivateFlag( );
      this->checkTimer->activateFlag( );

      this->checkTimer->updateReferenceMillis( );
      return false;
    }
  }
  return false;
}

bool RFIDController::read( ) { return false; }

BasicRFIDFrame* RFIDController::getBasicFrame( ) { return &this->basicFrame; }

void RFIDController::setLcd(LcdWrapper* newLcd) {
#if IN_OUT_RFID_DEBUG
  Serial.print(SERIAL_DEBUG_TAG);
  Serial.println(F("Setting RFID Lcd"));
#endif

  this->lcd = newLcd;
}
