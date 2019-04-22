#include "Contact.h"

Contact::Contact(char *_ID, char *_name, char *_surname, char *_mail,
                 char *_phoneNumber) {
  snprintf(this->ID, MAX_SIZE_ID, "%s", _ID);
  snprintf(this->name, MAX_SIZE_NAME, "%s", _name);
  snprintf(this->surname, MAX_SIZE_SURNAME, "%s", _surname);
  snprintf(this->mail, MAX_SIZE_MAIL, "%s", _mail);
  snprintf(this->phoneNumber, MAX_SIZE_PHONENUMBER, "%s", _phoneNumber);
}

void Contact::setID(char *newID) {
  snprintf(this->ID, MAX_SIZE_ID, "%s", newID);
}
void Contact::setName(char *newName) {
  snprintf(this->name, MAX_SIZE_NAME, "%s", newName);
}
void Contact::setSurname(char *newSurName) {
  snprintf(this->surname, MAX_SIZE_SURNAME, "%s", newSurName);
}
void Contact::setMail(char *newMail) {
  snprintf(this->mail, MAX_SIZE_MAIL, "%s", newMail);
}
void Contact::setPhoneNumer(char *newPhoneNumber) {
  snprintf(this->phoneNumber, MAX_SIZE_PHONENUMBER, "%s", newPhoneNumber);
}

char *Contact::getID() { return this->ID; }
char *Contact::getName() { return this->name; }
char *Contact::getSurname() { return this->surname; }
char *Contact::getMail() { return this->mail; }
char *Contact::getPhoneNumber() { return this->phoneNumber; }

void Contact::showSerialData() {
#if SERIAL_DEBUG
  Serial.print(F("Contacto : "));
  Serial.print(this->name);
  Serial.print(F(" "));
  Serial.println(this->surname);

  Serial.print(F("ID : "));
  Serial.println(this->ID);

  Serial.print(F("Mail : "));
  Serial.println(this->mail);

  Serial.print(F("Phone Number : "));
  Serial.println(this->phoneNumber);
#endif
}

void Contact::showLcdData() {
#if LCD_DEBUG
  // code here
#endif
}

void Contact::clear() {
  memset(this->ID, '\0', MAX_SIZE_ID);
  memset(this->name, '\0', MAX_SIZE_NAME);
  memset(this->surname, '\0', MAX_SIZE_SURNAME);
  memset(this->mail, '\0', MAX_SIZE_MAIL);
  memset(this->phoneNumber, '\0', MAX_SIZE_PHONENUMBER);
}
