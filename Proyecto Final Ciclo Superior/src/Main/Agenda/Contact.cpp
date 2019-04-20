#include "Contact.h"

Contact::Contact(char *ID, char *name, char *surname, char *mail,
                 char *phoneNumber) {
  snprintf(Contact::ID, MAX_SIZE_ID, "%s", ID);
  snprintf(Contact::name, MAX_SIZE_NAME, "%s", name);
  snprintf(Contact::surname, MAX_SIZE_SURNAME, "%s", surname);
  snprintf(Contact::mail, MAX_SIZE_MAIL, "%s", mail);
  snprintf(Contact::phoneNumber, MAX_SIZE_PHONENUMBER, "%s", phoneNumber);
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
