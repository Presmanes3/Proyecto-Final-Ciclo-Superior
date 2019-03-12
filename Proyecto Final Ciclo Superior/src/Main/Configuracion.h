#ifndef _CONF_H_
#define _CONF_H_

/*The aim of this file is to set strings, values for the timers and other
 * features that we can control in our program*/

#include "Configuracion_Personal.h"

/*====================================================================*/

/*Control Emergency Door*/
#define TIME_TO_CHECK_EMERGENCY_DOOR 500 // Milliseconds

/*Control Capacity*/
#define TIME_TO_CHECK_CAPACITY 20 // Milliseconds
#define MAX_CAPACITY 50

/*Control Smart Corridor Light*/
#define TIME_TO_CHECK_CORRIDOR_LIGHT 1 // Seconds

/*Control Temp*/
#define TIME_TO_CHECK_TEMP 250 // Milliseconds

/*Control External Light*/
#define TIME_TO_CHECK_EXTERNAL_LIGHT 250 // Milliseconds
#define LDR_THRESHOLD 512

/*Control Humidity*/
#define TIME_TO_CHECK_HUMIDITY 250 // Milliseconds

/*====================================================================*/

/*In Out Barrier*/
#define TIME_TO_CHECK_IN_OUT_BARRIER 50

/*In Out RFID*/
#define TIME_TO_CHECK_IN_OUT_RFID 50

/*In Out Manual*/
#define TIME_TO_CHECK_IN_OUT_MANUAL 50

#endif
