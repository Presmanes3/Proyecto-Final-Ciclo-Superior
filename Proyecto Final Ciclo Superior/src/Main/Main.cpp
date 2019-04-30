#include "Common.h"
#include "Dependencies.h"
#include "Functionalities.h"


void Main_program();

/* ======================= Timers ======================= */
#if SPECTS_BASIC
#if CONTROL_EMERGERCY_DOOR
Timer EmerDoorCheck = Timer(TIME_TO_CHECK_EMERGENCY_DOOR, millis(), true);
Timer EmerDoorStandBy = Timer(INACTIVE_TIME_EMERGENCY_DOOR, millis(), false);
#endif

#if CONTROL_SMART_CORRIDOR_LIGHT
Timer CorrLightCheck = Timer(TIME_TO_CHECK_CORRIDOR_LIGHT, millis(), true);
Timer CorrLightStandBy = Timer(INACTIVE_TIME_CORRIDOR_LIGHT, millis(), false);
#endif

#if CONTROL_TEMP
Timer TempCheck = Timer(TIME_TO_CHECK_TEMP, millis(), true);
Timer TempStandBy = Timer(INACTIVE_TIME_TEMPERATURE, millis(), false);
#endif

#if CONTROL_EXTERNAL_LIGHT
Timer LdrCheck = Timer(TIME_TO_CHECK_EXTERNAL_LIGHT, millis(), true);
Timer LdrStandBy = Timer(INACTIVE_TIME_EXTERNAL_LIGHT, millis(), false);
#endif

#if CONTROL_HUMIDITY
Timer DhtCheck = Timer(TIME_TO_CHECK_HUMIDITY, millis(), true);
Timer DhtStandBy = Timer(INACTIVE_TIME_HUMIDITY, millis(), false);
#endif
#endif

#if SPECTS_EXTRA
#if IN_OUT_RFID
Timer RfidCheck = Timer(TIME_TO_CHECK_IN_OUT_RFID, 0, true);
Timer RfidStandBy = Timer(INACTIVE_TIME_RFID, millis(), false);
#endif

#if IN_OUT_MANUAL
Timer ManualDoorCheck = Timer(TIME_TO_CHECK_IN_OUT_MANUAL, millis(), true);
Timer ManualDoorStandBy = Timer(INACTIVE_TIME_MANUAL, millis(), false);
#endif
#endif

/* ======================= Global Objects ======================= */

Equip myEquip;
Agenda myAgenda;
TimeManager timeManager;
CapacityManager myCapacityManager(MAX_CAPACITY);

#if SPECTS_BASIC
#if CONTROL_EMERGERCY_DOOR
EmerDoorController myEmerDoorCont(&timeManager, &EmerDoorCheck, &EmerDoorStandBy);
#endif

#if CONTROL_SMART_CORRIDOR_LIGHT
PIRController myPIR(&timeManager, &CorrLightCheck, &CorrLightStandBy);
#endif

#if CONTROL_TEMP
CustomProbeClass myProbe(&timeManager, &TempCheck, &TempStandBy);
#endif

#if CONTROL_EXTERNAL_LIGHT
LDRController myLDR(&timeManager, &LdrCheck, &LdrStandBy);
#endif

#if CONTROL_HUMIDITY
CustomDHTClass myDHT(&timeManager, &DhtCheck, &DhtStandBy);
#endif
#endif

#if SPECTS_EXTRA
#if IN_OUT_RFID
RFIDController myRFID(&myAgenda, &timeManager, &RfidCheck, &RfidStandBy);
#endif

#if IN_OUT_MANUAL
ManualDoorController myManualDoorController(
    &myCapacityManager, &timeManager, &ManualDoorCheck, &ManualDoorStandBy);
#endif
#endif
/* ======================================================= */

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  myEquip.setup();
  myAgenda.Setup();

   #if CONTROL_CAPACITY
      myCapacityManager.setup();
    #endif

  #if SPECTS_BASIC
    #if CONTROL_EMERGERCY_DOOR
      myEmerDoorCont.setup();
    #endif

    #if CONTROL_SMART_CORRIDOR_LIGHT
      myPIR.setup();
    #endif

    #if CONTROL_TEMP
      myProbe.setup();
    #endif

    #if CONTROL_EXTERNAL_LIGHT
      myLDR.setup();
    #endif

    #if CONTROL_HUMIDITY
      myDHT.setup();
    #endif

  #endif

  #if SPECTS_EXTRA
  
    #if IN_OUT_BARRIER
    #endif

    #if IN_OUT_RFID
      myRFID.setup();
    #endif

    #if IN_OUT_MANUAL
      myManualDoorController.setup();
    #endif
  #endif
}

void loop()
{
  // put your main code here, to run repeatedly:
  // myRFID.Read(myAgenda.Contact_List, 2, );

  Main_program();
}

void Main_program()
{

  #if SPECTS_BASIC
    #if CONTROL_EMERGERCY_DOOR
      myEmerDoorCont.run();
      /*if (EmergencyDoorCheck.flag) {
        // myEmergencyDoor.run();
        if (Past_mil(EmergencyDoorCheck.time, EmergencyDoorCheck.var)) {
          // Read the button
          if (myEmergencyDoor.Read()) {

            myEmergencyDoor.Turn_on_light();
            EmergencyDoorCheck.flag = false;
          }
        }
      } else {
        if (Past_sec(INACTIVE_TIME_EMERGENCY_DOOR, EmergencyDoorCheck.var)) {
          myEmergencyDoor.Turn_off_light();
          EmergencyDoorCheck.flag = true;
        }
    }*/
    #endif

    #if CONTROL_SMART_CORRIDOR_LIGHT
      myPIR.run();
      /*if (CorridorLightCheck.flag) {
        if (Past_sec(CorridorLightCheck.time, CorridorLightCheck.var)) {
          if (myPIR.Read()) {
            myPIR.Turn_on_light();
          }
        }
      } else {
        if (Past_min(INACTIVE_TIME_CORRIDOR_LIGHT, CorridorLightCheck.var))
{ myPIR.Turn_off_light(); CorridorLightCheck.flag = true;
        }
    }*/
    #endif

    #if CONTROL_TEMP
      myProbe.run();
      /* if (TempCheck.flag) {
         if (Past_mil(TempCheck.time, TempCheck.var)) {
           myProbe.Read();
           myProbe.Show();
           TempCheck.flag = false;
         }
       } else {
         if (Past_min(INACTIVE_TIME_TEMPERATURE, TempCheck.var)) {
           TempCheck.flag = true;
         }
     }*/
    #endif

    #if CONTROL_EXTERNAL_LIGHT
      myLDR.run();
      /* if (LDRCheck.flag) {
         if (Past_mil(LDRCheck.time, LDRCheck.var)) {
           if (myLDR.Read()) {
             myLDR.Turn_on_light();
             LDRCheck.flag = false;
           }
         }
       } else {
         if (Past_min(INACTIVE_TIME_EXTERNAL_LIGHT, LDRCheck.var)) {
           myLDR.Turn_off_light();
           LDRCheck.flag = true;
         }
     }*/
    #endif

    #if CONTROL_HUMIDITY
      myDHT.run();
      /* if (HumidityCheck.flag) {
         if (Past_mil(HumidityCheck.time, HumidityCheck.var)) {
           myDHT.Read();
           myDHT.Show();
           HumidityCheck.flag = false;
         }
       } else {
         if (Past_min(INACTIVE_TIME_HUMIDITY, HumidityCheck.var)) {

           HumidityCheck.flag = true;
         }
       }
   }*/
    #endif
  #endif

  #if SPECTS_EXTRA
  
    #if IN_OUT_BARRIER
    #endif 

    #if IN_OUT_RFID
      myRFID.run();
      /*if (RFIDCheck.flag) {
        if (Past_mil(RFIDCheck.time, RFIDCheck.var)) {
          if () {
            Serial.println(F("===== Leyendo RFID Sensor ====="));
          }
          if (myRFID.Read(myRFID.getAgenda()->ContactList, 2, )) {
            RFIDCheck.flag = false;
          }
        }
      } else {
        if (Past_sec(INACTIVE_TIME_RFID, RFIDCheck.var)) {

          RFIDCheck.flag = true;
        }
    }*/
    #endif

    #if IN_OUT_MANUAL
      myManualDoorController.run();
      /* if (ManualDoorCheck.flag) {
         if (Past_mil(ManualDoorCheck.time, ManualDoorCheck.var)) {
           if (myManualDoorController.Read()) {
             myManualDoorController.Turn_on_light();
             if (myManualDoorController.getButtonOption()) {
               myCapacityManager.Add();
             }
             { myCapacityManager.Substract(); }
           }
       }else{
       myCapacityManager.Substract();
   }
       } else {
         if (Past_mil(INACTIVE_TIME_MANUAL, ManualDoorCheck.var)) {
           myManualDoorController.Turn_off_light();
           ManualDoorCheck.flag = false;
         }
     }*/
    #endif
  #endif
}
