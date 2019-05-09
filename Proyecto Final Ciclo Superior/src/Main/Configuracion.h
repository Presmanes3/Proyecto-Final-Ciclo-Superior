/*The aim of this file is to set strings, values for the timers and other
 * features that we can control in our program*/

#ifndef _CONF_H_
#define _CONF_H_

#include "Configuracion_Personal.h"

/*====================================================================*/

/*Control Emergency Door*/
#define TIME_TO_CHECK_EMERGENCY_DOOR   500  // Milliseconds
#define INACTIVE_TIME_EMERGENCY_DOOR   5    // Seconds

/*Control Capacity*/
#define TIME_TO_CHECK_CAPACITY         20   // Milliseconds
#define INACTIVE_TIME_CAPACITY         40   // Milliseconds
#define MAX_CAPACITY                   50

/*Control Smart Corridor Light*/
#define TIME_TO_CHECK_CORRIDOR_LIGHT   1    // Seconds
#define INACTIVE_TIME_CORRIDOR_LIGHT   30   // Seconds

/*Control Temp*/
#define TIME_TO_CHECK_TEMP             250  // Milliseconds
#define INACTIVE_TIME_TEMPERATURE      1    // Minutes

/*Control External Light*/
#define TIME_TO_CHECK_EXTERNAL_LIGHT   250  // Milliseconds
#define INACTIVE_TIME_EXTERNAL_LIGHT   10  // Seconds
#define LDR_THRESHOLD                  512

/*Control Humidity*/
#define TIME_TO_CHECK_HUMIDITY         250  // Milliseconds
#define INACTIVE_TIME_HUMIDITY         1    // Minutes

/*====================================================================*/

/*In Out Barrier*/
#define TIME_TO_CHECK_IN_OUT_BARRIER   50   // Milliseconds
#define INACTIVE_TIME_BARRIER          100  // Milliseconds

/*In Out RFID*/
#define TIME_TO_CHECK_IN_OUT_RFID      500   // Milliseconds
#define INACTIVE_TIME_RFID             5    // Seconds

/*In Out Manual*/
#define TIME_TO_CHECK_IN_OUT_MANUAL    50   // Milliseconds
#define INACTIVE_TIME_MANUAL           250   // Milliseconds

#endif
