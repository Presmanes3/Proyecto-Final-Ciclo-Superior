/* The aim of this file is to manage the Debug of each functionality both
 * through Serial or LCD*/

#ifndef _DEBUG_H_
#define _DEBUG_H_

#define MAIN_DEBUG true                 // Controls Debug functionality
#define SERIAL_DEBUG MAIN_DEBUG && true // Allows Serial Debug
#define SERIAL_GUI MAIN_DEBUG && true   // Aloows Serial GUI
#define LCD_DEBUG MAIN_DEBUG && true    // Allows LCD GUI

/*===========================================*/
#if SERIAL_DEBUG // S.Debug

#  define EMER_DOOR_DEBUG false            // Act/Deact Emergency Door S.Debug
#  define CAPACITY_DEBUG false             // Act/Deact Capacity Manager S.Debug
#  define SMART_CORRIDOR_LIGHT_DEBUG false // Act/Deact PIR Class S.Debug
#  define TEMP_PROBE_DEBUG false           // Act/Deact Temperature S.Debug
#  define EXTERNAL_LIGHT_DEBUG false       // Act/Deact LDR Class S.Debug
#  define DHT_DEBUG false                  // Act/Deact Humidity S.Debug
#  define IN_OUT_RFID_DEBUG false          // Act/Deact RFID Class S.Debug
#  define IN_OUT_MANUAL_DEBUG false        // Act/Deact Manual Door S.Debug
#  define LCD_SERIAL_DEBUG false           // Act/Deact LCD Class S.Debug
#endif                                     // SERIAL_DEBUG
/*===========================================*/

#if SERIAL_GUI // S.Debug

#  define EMER_DOOR_SERIAL_GUI true // Act/Deact Emer Door S.GUI
#  define CAPACITY_SERIAL_GUI true  // Act/Deact Capacity Manager S.GUI
#  define SMART_CORRIDOR_LIGHT_SERIAL_GUI true // Act/Deact Corridor S.GUI
#  define TEMP_PROBE_SERIAL_GUI true           // Act/Deact Temperature S.GUI
#  define EXTERNAL_LIGHT_SERIAL_GUI true       // Act/Deact Ext. Light S.GUI
#  define DHT_SERIAL_GUI true                  // Act/Deact Humidity S.GUI
#  define IN_OUT_RFID_SERIAL_GUI true          // Act/Deact RFID Class S.GUI
#  define IN_OUT_MANUAL_SERIAL_GUI true        // Act/Deact Manual Door S.GUI
#endif                                         // SERIAL_GUI
/*===========================================*/

#if LCD_DEBUG // LCD GUI

#  define TEMP_LCD_DEBUG true           // Act/Deact Temperature GUI
#  define HUMIDITY_LCD_DEBUG false      // Act/Deact Humidity GUI
#  define IN_OUT_RFID_LCD_DEBUG true    // Act/Deact RFID GUI
#  define IN_OUT_MANUAL_LCD_DEBUG false // Act/Deact Manual Door GUI
#endif                                  // !SERIAL_DEBUG && LCD_DEBUG
/*===========================================*/

#define SERIAL_SPLITTER "======================================="
#define SERIAL_DEBUG_TAG "[DEBUG] "
#define SERIAL_TAB "[******] "

#endif // _DEBUG_H_
