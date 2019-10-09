/* The aim of this File is to activate or deactivate each individual
 * functionality the main program is able to handle
 */

#ifndef _FUNCTIONALITIES_H_
#define _FUNCTIONALITIES_H_

#define SPECTS_BASIC true // Activate/Deactivate Basic Functionalities
#define SPECTS_EXTRA true // Activate/Deactivate Extra Functionalities

/*Basic Features*/
#if SPECTS_BASIC
#  define CONTROL_EMERGERCY_DOOR true // Activate/Deactivate Emergeny Door
#  define CONTROL_CAPACITY true       // Activate/Deactivate Capacity Manager
#  define CONTROL_SMART_CORRIDOR_LIGHT true // Activate/Deactivate PIR
#  define CONTROL_TEMP true           // Activate/Deactivate Temperature Control
#  define CONTROL_EXTERNAL_LIGHT true // Activate/Deactivate LDR
#  define CONTROL_HUMIDITY true       // Activate/Deactivate Humidity Control
#endif

/*Extra Features*/
#if SPECTS_EXTRA
#  define IN_OUT_BARRIER false // Activate/Deactivate Barrior Control
#  define IN_OUT_RFID true     // Activate/Deactivate RFID Control
#  define IN_OUT_MANUAL true   // Activate/Deactivate Manual Control
#endif
#endif
