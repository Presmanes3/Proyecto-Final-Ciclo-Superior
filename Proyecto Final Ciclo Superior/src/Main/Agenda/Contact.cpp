#include "Contact.h"

Contact::Contact(char *_ID, char *_name, char *_surname, char *_mail,
                 char *_phoneNumber) {
  snprintf(Contact::ID, MAX_SIZE_ID, "%s", _ID);
  snprintf(Contact::name, MAX_SIZE_NAME, "%s", _name);
  snprintf(Contact::surname, MAX_SIZE_SURNAME, "%s", _surname);
  snprintf(Contact::mail, MAX_SIZE_MAIL, "%s", _mail);
  snprintf(Contact::phoneNumber, MAX_SIZE_PHONENUMBER, "%s", _phoneNumber);
}

void Contact::setID(char *newID) {
  snprintf(Contact::ID, MAX_SIZE_ID, "%s", newID);
}
void Contact::setName(char *newName) {
  snprintf(Contact::name, MAX_SIZE_NAME, "%s", newName);
}
void Contact::setSurname(char *newSurName) {
  snprintf(Contact::surname, MAX_SIZE_SURNAME, "%s", newSurName);
}
void Contact::setMail(char *newMail) {
  snprintf(Contact::mail, MAX_SIZE_MAIL, "%s", newMail);
}
void Contact::setPhoneNumer(char *newPhoneNumber) {
  snprintf(Contact::phoneNumber, MAX_SIZE_PHONENUMBER, "%s", newPhoneNumber);
}

char *Contact::getID() { return Contact::ID; }
char *Contact::getName() { return Contact::name; }
char *Contact::getSurname() { return Contact::surname; }
char *Contact::getMail() { return Contact::mail; }
char *Contact::getPhoneNumber() { return Contact::phoneNumber; }

void Contact::showSerialData() {

  Serial.print(F("Contacto : "));
  Serial.print(Contact::name);
  Serial.print(F(" "));
  Serial.println(Contact::surname);

  Serial.print(F("ID : "));
  Serial.println(Contact::ID);

  Serial.print(F("Mail : "));
  Serial.println(Contact::mail);

  Serial.print(F("Phone Number : "));
  Serial.println(Contact::phoneNumber);
}

void Contact::clear() {
  memset(Contact::ID, '\0', MAX_SIZE_ID);
  memset(Contact::name, '\0', MAX_SIZE_NAME);
  memset(Contact::surname, '\0', MAX_SIZE_SURNAME);
  memset(Contact::mail, '\0', MAX_SIZE_MAIL);
  memset(Contact::phoneNumber, '\0', MAX_SIZE_PHONENUMBER);
}
