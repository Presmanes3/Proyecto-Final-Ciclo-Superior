
#include "Common.h"
#include "Dependencies.h"
#include "Functionalities.h"

void Main_program( );
#if SERIAL_GUI
void setupShowFunctionalities( );
#endif

/* ======================= Timers ======================= */
#if SPECTS_BASIC
#  if CONTROL_EMERGERCY_DOOR
Timer EmerDoorCheck   = Timer(TIME_TO_CHECK_EMERGENCY_DOOR, millis( ), true);
Timer EmerDoorStandBy = Timer(INACTIVE_TIME_EMERGENCY_DOOR, millis( ), false);
#  endif

#  if CONTROL_SMART_CORRIDOR_LIGHT
Timer CorrLightCheck   = Timer(TIME_TO_CHECK_CORRIDOR_LIGHT, millis( ), true);
Timer CorrLightStandBy = Timer(INACTIVE_TIME_CORRIDOR_LIGHT, millis( ), false);
#  endif

#  if CONTROL_TEMP
Timer TempCheck   = Timer(TIME_TO_CHECK_TEMP, millis( ), true);
Timer TempStandBy = Timer(INACTIVE_TIME_TEMPERATURE, millis( ), false);
#  endif

#  if CONTROL_EXTERNAL_LIGHT
Timer LdrCheck   = Timer(TIME_TO_CHECK_EXTERNAL_LIGHT, millis( ), true);
Timer LdrStandBy = Timer(INACTIVE_TIME_EXTERNAL_LIGHT, millis( ), false);
#  endif

#  if CONTROL_HUMIDITY
Timer DhtCheck   = Timer(TIME_TO_CHECK_HUMIDITY, millis( ), true);
Timer DhtStandBy = Timer(INACTIVE_TIME_HUMIDITY, millis( ), false);
#  endif
#endif

#if SPECTS_EXTRA
#  if IN_OUT_RFID
Timer RfidCheck   = Timer(TIME_TO_CHECK_IN_OUT_RFID, 0, true);
Timer RfidStandBy = Timer(INACTIVE_TIME_RFID, millis( ), false);
#  endif

#  if IN_OUT_MANUAL
Timer ManualDoorCheck   = Timer(TIME_TO_CHECK_IN_OUT_MANUAL, millis( ), true);
Timer ManualDoorStandBy = Timer(INACTIVE_TIME_MANUAL, millis( ), false);
#  endif
#endif

/* ======================= Global Objects ======================= */

#if LCD_DEBUG
LcdWrapper mainLcd(0x27, 16, 2);
#endif

Equip           myEquip;
Agenda          myAgenda;
TimeManager     timeManager;
CapacityManager myCapacityManager(MAX_CAPACITY, &mainLcd);

#if SPECTS_BASIC
#  if CONTROL_EMERGERCY_DOOR
EmerDoorController myEmerDoorCont(&timeManager, &EmerDoorCheck,
                                  &EmerDoorStandBy);
#  endif

#  if CONTROL_SMART_CORRIDOR_LIGHT
PIRController myPIR(&timeManager, &CorrLightCheck, &CorrLightStandBy);
#  endif

#  if CONTROL_TEMP
CustomProbeClass myProbe(&timeManager, &TempCheck, &TempStandBy, &mainLcd);
#  endif

#  if CONTROL_EXTERNAL_LIGHT
LDRController myLDR(LDR_THRESHOLD, &timeManager, &LdrCheck, &LdrStandBy);
#  endif

#  if CONTROL_HUMIDITY
CustomDHTClass myDHT(&timeManager, &DhtCheck, &DhtStandBy, &mainLcd);
#  endif
#endif

#if SPECTS_EXTRA
#  if IN_OUT_RFID
RFIDController myRFID(&myAgenda, &timeManager, &RfidCheck, &RfidStandBy,
                      &mainLcd);
#  endif

#  if IN_OUT_MANUAL
ManualDoorController myManualDoorController(&myCapacityManager, &timeManager,
                                            &ManualDoorCheck,
                                            &ManualDoorStandBy);
#  endif
#endif
/* ======================================================= */

LiquidCrystal_I2C lcd(0x27, 16, 2);

/* ======================================================= */

void setup( ) {
// put your setup code here, to run once:
#if MAIN_DEBUG
  Serial.begin(115200);
#endif

  myEquip.setup( );
  myAgenda.Setup( );

#if SERIAL_GUI
  setupShowFunctionalities( );
#endif

#if CONTROL_CAPACITY
  myCapacityManager.setup( );
  myCapacityManager.getBasicFrame( )->setName("Capacity1");
#endif

#if SPECTS_BASIC
#  if CONTROL_EMERGERCY_DOOR
  myEmerDoorCont.setup( );
#  endif

#  if CONTROL_SMART_CORRIDOR_LIGHT
  myPIR.setup( );
#  endif

#  if CONTROL_TEMP
  myProbe.setup( );

#    if TEMP_LCD_DEBUG
  myProbe.setLcd(&mainLcd);
#    endif
#  endif

#  if CONTROL_EXTERNAL_LIGHT
  myLDR.setup( );
#  endif

#  if CONTROL_HUMIDITY
  myDHT.setup( );
#  endif

#endif

#if SPECTS_EXTRA
#  if IN_OUT_BARRIER
#  endif

#  if IN_OUT_RFID
  myRFID.setup( );

#    if IN_OUT_RFID_LCD_DEBUG
  myRFID.setLcd(&mainLcd);
#    endif
#  endif

#  if IN_OUT_MANUAL
  myManualDoorController.setup( );
#  endif
#endif

#if LCD_DEBUG
  mainLcd.setup( );
  mainLcd.setDefaultFrame(myCapacityManager.getBasicFrame( ));
  mainLcd.changeFrame(myCapacityManager.getBasicFrame( ));

#  if CONTROL_TEMP && TEMP_LCD_DEBUG
  myProbe.getBasicFrame( )->setName("Sondas1");
  // mainLcd.addFrame(myProbe.getBasicFrame( ));
#  endif

#  if CONTROL_HUMIDITY && HUMIDITY_LCD_DEBUG
  myDHT.getBasicFrame( )->setName("DHT1");
  /// mainLcd.addFrame(myDHT.getBasicFrame( ));
#  endif

#  if IN_OUT_RFID && IN_OUT_RFID_LCD_DEBUG
  myRFID.getBasicFrame( )->setName("RFID1");
  // mainLcd.addFrame(myRFID.getBasicFrame( ));
#  endif
#endif
}

void loop( ) { Main_program( ); }

void Main_program( ) {
#if LCD_DEBUG
  mainLcd.update( );
#endif

#if SPECTS_BASIC
#  if CONTROL_EMERGERCY_DOOR
  myEmerDoorCont.run( );
#  endif

#  if CONTROL_SMART_CORRIDOR_LIGHT
  myPIR.run( );
#  endif

#  if CONTROL_TEMP
  myProbe.run( );
#  endif

#  if CONTROL_EXTERNAL_LIGHT
  myLDR.run( );
#  endif

#  if CONTROL_HUMIDITY
  myDHT.run( );
#  endif
#endif

#if SPECTS_EXTRA

#  if IN_OUT_BARRIER
#  endif

#  if IN_OUT_RFID
  if(myRFID.run( )) { myCapacityManager.addPerson( ); }
#  endif

#  if IN_OUT_MANUAL
  myManualDoorController.run( );
#  endif
#endif
}

#if SERIAL_GUI
void setupShowFunctionalities( ) {
  Serial.println( );
  Serial.println(F("=========== Mostrando Funcionalidades ==========="));
  Serial.print(F(SERIAL_TAB));
  Serial.print(F("Control de Emergencia : "));
  Serial.println(CONTROL_EMERGERCY_DOOR);
  Serial.print(F(SERIAL_TAB));
  Serial.print(F("Control de Aforo : "));
  Serial.println(CONTROL_CAPACITY);
  Serial.print(F(SERIAL_TAB));
  Serial.print(F("Control de Pasillos Inteligente : "));
  Serial.println(CONTROL_SMART_CORRIDOR_LIGHT);
  Serial.print(F(SERIAL_TAB));
  Serial.print(F("Control de Temperatura : "));
  Serial.println(CONTROL_TEMP);
  Serial.print(F(SERIAL_TAB));
  Serial.print(F("Control de Luz Externa : "));
  Serial.println(CONTROL_EXTERNAL_LIGHT);
  Serial.print(F(SERIAL_TAB));
  Serial.print(F("Control de Humedad Relativa : "));
  Serial.println(CONTROL_HUMIDITY);
  Serial.print(F(SERIAL_TAB));
  Serial.print(F("Control de Aforo RFID : "));
  Serial.println(IN_OUT_RFID);
  Serial.print(F(SERIAL_TAB));
  Serial.print(F("Control de Aforo Manual : "));
  Serial.println(IN_OUT_MANUAL);
  Serial.println(F(SERIAL_SPLITTER));
  Serial.println( );
}
#endif
