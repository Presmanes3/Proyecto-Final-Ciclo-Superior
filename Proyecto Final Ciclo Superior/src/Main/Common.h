/*The aim of this file is to set all the values related with the pins used in
 * arduino for functionalities*/

#ifndef _COMMON_H_
#define _COMMON_H_

#include "Debug.h"
#include "Configuracion.h"

#include "EventClass/EventManager.h"

#include "SensorAbstractClass/SensorClass.h"

#include "TimerClass/TimeManager.h"
#include "TimerClass/Timer.h"

#include "LCDWrapper/LCDFrame.h"

/*====================================================================*/

/*Control Emergency Door*/
#define EMERGENCY_DOOR_PIN 22
#define EMERGENCY_LED 4

/*Control Smart Corridor Light*/
#define PIR_PIN 10
#define PIR_LED 2

/*Control Temp*/
#define PROBE_NUM_PROBES 2
#define PROBE_DATA_PIN 49

/*Control External Light*/
#define LDR_PIN A1
#define LDR_LED 3

/*Control Humidity*/
#define DHT_PIN 12
#define DHT_TYPE DHT22

/*====================================================================*/

/*In Out Barrier*/

/*In Out RFID*/
#define RFID_SDA 9
#define RFID_SCK 52
#define RFID_MOSI 51
#define RFID_MISO 50
#define RFID_RST 8

/*In Out Manual*/
#define MANUAL_DOOR_IN_PIN 23
#define MANUAL_DOOR_OUT_PIN 24

#define MANUAL_OUT_LED 6
#define MANUAL_IN_LED 5

/*====================================================================*/


#endif
