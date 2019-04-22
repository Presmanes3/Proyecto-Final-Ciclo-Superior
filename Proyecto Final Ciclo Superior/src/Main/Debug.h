#ifndef _DEBUG_H_
#define _DEBUG_H_

#define MAIN_DEBUG true

#define SERIAL_DEBUG MAIN_DEBUG && true
#define LCD_DEBUG MAIN_DEBUG && true

/*===========================================*/
#if SERIAL_DEBUG

#define EMER_DOOR_DEBUG true
#define CAPACITY_DEBUG true
#define SMART_CORRIDOR_LIGHT_DEBUG true
#define TEMP_DEBUG true
#define EXTERNAL_LIGHT_DEBUG true
#define HUMIDITY_DEBUG true

#define IN_OUT_RFID_DEBUG true
#define IN_OUT_MANUAL_DEBUG true

#endif // SERIAL_DEBUG
/*===========================================*/

#if LCD_DEBUG

#define TEMP_LCD_DEBUG true
#define HUMIDITY_LCD_DEBUG true
#define IN_OUT_RFID_LCD_DEBUG true
#define IN_OUT_MANUAL_LCD_DEBUG true

#endif // !SERIAL_DEBUG && LCD_DEBUG
/*===========================================*/
#endif // _DEBUG_H_
