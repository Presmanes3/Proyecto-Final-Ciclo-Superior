/* The aim of this file is to manage the Debug of each functionality both through Serial or LCD*/

#ifndef _DEBUG_H_
#define _DEBUG_H_

#define MAIN_DEBUG                   true  // Controls Debug functionality

#define SERIAL_DEBUG MAIN_DEBUG &&   true  // Allows Serial Debug
#define LCD_DEBUG MAIN_DEBUG &&      true  // Allows LCD GUI

/*===========================================*/
#if SERIAL_DEBUG  //S.Debug

#define EMER_DOOR_DEBUG              true  // Activate/Deactivate Emergency Door S.Debug
#define CAPACITY_DEBUG               true  // Activate/Deactivate Capacity Manager S.Debug
#define SMART_CORRIDOR_LIGHT_DEBUG   true  // Activate/Deactivate PIR Class S.Debug
#define TEMP_PROBE_DEBUG             true  // Activate/Deactivate Temperature S.Debug
#define EXTERNAL_LIGHT_DEBUG         true  // Activate/Deactivate LDR Class S.Debug
#define DHT_DEBUG                    true  // Activate/Deactivate Humidity S.Debug

#define IN_OUT_RFID_DEBUG            true  // Activate/Deactivate RFID Class S.Debug
#define IN_OUT_MANUAL_DEBUG          true  // Activate/Deactivate Manual Door S.Debug

#define LCD_SERIAL_DEBUG             true  // Activate/Deactivate LCD Class S.Debug

#endif // SERIAL_DEBUG
/*===========================================*/

#if LCD_DEBUG  // LCD GUI

#define TEMP_LCD_DEBUG               true  // Activate/Deactivate Temperature GUI
#define HUMIDITY_LCD_DEBUG           true  // Activate/Deactivate Humidity GUI
#define IN_OUT_RFID_LCD_DEBUG        true  // Activate/Deactivate RFID GUI
#define IN_OUT_MANUAL_LCD_DEBUG      true  // Activate/Deactivate Manual Door GUI

#endif // !SERIAL_DEBUG && LCD_DEBUG
/*===========================================*/
#endif // _DEBUG_H_
