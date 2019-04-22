#ifndef _CONTACT_H_
#define _CONTACT_H_

#include "Arduino.h"

#define MAX_SIZE_ID 15
#define MAX_SIZE_NAME 15
#define MAX_SIZE_SURNAME 15
#define MAX_SIZE_MAIL 30
#define MAX_SIZE_PHONENUMBER 10

class Contact {
public:
  Contact(char *_ID, char *_name, char *_surname, char *_mail,
          char *_phoneNumber);

  /*===== Setters =====*/
  void setID(char *newID);
  void setName(char *newName);
  void setSurname(char *newSurName);
  void setMail(char *newMail);
  void setPhoneNumer(char *newPhoneNumber);

  /*===== Getters =====*/
  char *getID();
  char *getName();
  char *getSurname();
  char *getMail();
  char *getPhoneNumber();

  /*=====     =====*/
  void showSerialData();
  void showLcdData();
  void clear();

private:
  char ID[MAX_SIZE_ID];
  char name[MAX_SIZE_NAME];
  char surname[MAX_SIZE_SURNAME];
  char mail[MAX_SIZE_MAIL];
  char phoneNumber[MAX_SIZE_PHONENUMBER];
};
#endif
