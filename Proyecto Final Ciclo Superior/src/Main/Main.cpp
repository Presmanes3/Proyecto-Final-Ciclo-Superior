#include "Common.h"
#include "Dependencies.h"
#include "Functionalities.h"

void Main_program();

/* ======================= Timers ======================= */

Timer EmerDoorCheck = Timer(TIME_TO_CHECK_EMERGENCY_DOOR, millis(), true);
Timer EmerDoorStandBy = Timer(INACTIVE_TIME_EMERGENCY_DOOR, millis(), false);

Timer CorrLightCheck = Timer(TIME_TO_CHECK_CORRIDOR_LIGHT, millis(), true);
Timer CorrLightStandBy = Timer(INACTIVE_TIME_CORRIDOR_LIGHT, millis(), false);

Timer TempCheck = Timer(TIME_TO_CHECK_TEMP, millis(), true);
Timer TempStandBy = Timer(INACTIVE_TIME_TEMPERATURE, millis(), false);

Timer LdrCheck = Timer(TIME_TO_CHECK_EXTERNAL_LIGHT, millis(), true);
Timer LdrStandBy = Timer(INACTIVE_TIME_EXTERNAL_LIGHT, millis(), false);

Timer DhtCheck = Timer(TIME_TO_CHECK_HUMIDITY, millis(), true);
Timer DhtStandBy = Timer(INACTIVE_TIME_HUMIDITY, millis(), false);

Timer RfidCheck = Timer(TIME_TO_CHECK_IN_OUT_RFID, 0, true);
Timer RfidStandBy = Timer(INACTIVE_TIME_RFID, millis(), false);

Timer ManualDoorCheck = Timer(TIME_TO_CHECK_IN_OUT_MANUAL, millis(), true);
Timer ManualDoorStandBy = Timer(INACTIVE_TIME_MANUAL, millis(), false);

/* ======================= Global Objects ======================= */

Agenda myAgenda = Agenda();
TimeManager timeManager = TimeManager();
CapacityManager myCapacityManager = CapacityManager(MAX_CAPACITY);

EmerDoorController myEmerDoorCont =
    EmerDoorController(&timeManager, &EmerDoorCheck, &EmerDoorStandBy);

PIRController myPIR =
    PIRController(&timeManager, &CorrLightCheck, &CorrLightStandBy);

PROBE myProbe = PROBE(&timeManager, &TempCheck, &TempStandBy);

LDRController myLDR = LDRController(&timeManager, &LdrCheck, &LdrStandBy);

DHT_S myDHT = DHT_S(&timeManager, &DhtCheck, &DhtStandBy);

RFIDController myRFID =
    RFIDController(&myAgenda, &timeManager, &RfidCheck, &RfidStandBy);

ManualDoorController myManualDoorController = ManualDoorController(
    &myCapacityManager, &timeManager, &ManualDoorCheck, &ManualDoorStandBy);

/* ======================================================= */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  EQUIPO::Setup(SERIAL_GUI);
  myAgenda.Setup(SERIAL_GUI);

  if (SPECTS_BASIC) {
    if (CONTROL_EMERGERCY_DOOR) {
      myEmerDoorCont.setup(SERIAL_GUI);
    }
    if (CONTROL_CAPACITY) {
      myCapacityManager.Setup(SERIAL_GUI);
    }
    if (CONTROL_SMART_CORRIDOR_LIGHT) {
      myPIR.setup(SERIAL_GUI);
    }
    if (CONTROL_TEMP) {
      myProbe.setup(SERIAL_GUI);
    }
    if (CONTROL_EXTERNAL_LIGHT) {
      myLDR.setup(SERIAL_GUI);
    }
    if (CONTROL_HUMIDITY) {
      myDHT.setup(SERIAL_GUI);
    }
  }
  if (SPECTS_EXTRA) {
    if (IN_OUT_BARRIER) {
    }
    if (IN_OUT_RFID) {
      myRFID.setup(SERIAL_GUI);
    }
    if (IN_OUT_MANUAL) {
      myManualDoorController.setup(SERIAL_GUI);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // myRFID.Read(myAgenda.Contact_List, 2, DEBUG);

  Main_program();
}

void Main_program() {

  if (SPECTS_BASIC) {
    if (CONTROL_EMERGERCY_DOOR) {
      myEmerDoorCont.run(DEBUG);
      /*if (EmergencyDoorCheck.flag) {
        // myEmergencyDoor.run();
        if (Past_mil(EmergencyDoorCheck.time, EmergencyDoorCheck.var)) {
          // Read the button
          if (myEmergencyDoor.Read(DEBUG)) {

            myEmergencyDoor.Turn_on_light(DEBUG);
            EmergencyDoorCheck.flag = false;
          }
        }
      } else {
        if (Past_sec(INACTIVE_TIME_EMERGENCY_DOOR, EmergencyDoorCheck.var)) {
          myEmergencyDoor.Turn_off_light(DEBUG);
          EmergencyDoorCheck.flag = true;
        }
    }*/
    }
    if (CONTROL_SMART_CORRIDOR_LIGHT) {
      myPIR.run(DEBUG);
      /*if (CorridorLightCheck.flag) {
        if (Past_sec(CorridorLightCheck.time, CorridorLightCheck.var)) {
          if (myPIR.Read(DEBUG)) {
            myPIR.Turn_on_light(DEBUG);
          }
        }
      } else {
        if (Past_min(INACTIVE_TIME_CORRIDOR_LIGHT, CorridorLightCheck.var))
{ myPIR.Turn_off_light(DEBUG); CorridorLightCheck.flag = true;
        }
    }*/
    }
    if (CONTROL_TEMP) {
      myProbe.run(DEBUG);
      /* if (TempCheck.flag) {
         if (Past_mil(TempCheck.time, TempCheck.var)) {
           myProbe.Read(DEBUG);
           myProbe.Show();
           TempCheck.flag = false;
         }
       } else {
         if (Past_min(INACTIVE_TIME_TEMPERATURE, TempCheck.var)) {
           TempCheck.flag = true;
         }
     }*/
    }
    if (CONTROL_EXTERNAL_LIGHT) {
      myLDR.run(DEBUG);
      /* if (LDRCheck.flag) {
         if (Past_mil(LDRCheck.time, LDRCheck.var)) {
           if (myLDR.Read(DEBUG)) {
             myLDR.Turn_on_light(DEBUG);
             LDRCheck.flag = false;
           }
         }
       } else {
         if (Past_min(INACTIVE_TIME_EXTERNAL_LIGHT, LDRCheck.var)) {
           myLDR.Turn_off_light(DEBUG);
           LDRCheck.flag = true;
         }
     }*/
    }
    if (CONTROL_HUMIDITY) {
      myDHT.run(DEBUG);
      /* if (HumidityCheck.flag) {
         if (Past_mil(HumidityCheck.time, HumidityCheck.var)) {
           myDHT.Read(DEBUG);
           myDHT.Show();
           HumidityCheck.flag = false;
         }
       } else {
         if (Past_min(INACTIVE_TIME_HUMIDITY, HumidityCheck.var)) {

           HumidityCheck.flag = true;
         }
       }
   }*/
    }
  }
  if (SPECTS_EXTRA) {
    if (IN_OUT_BARRIER) {
    }
    if (IN_OUT_RFID) {
      myRFID.run(DEBUG);
      /*if (RFIDCheck.flag) {
        if (Past_mil(RFIDCheck.time, RFIDCheck.var)) {
          if (DEBUG) {
            Serial.println(F("===== Leyendo RFID Sensor ====="));
          }
          if (myRFID.Read(myRFID.getAgenda()->ContactList, 2, SERIAL_GUI)) {
            RFIDCheck.flag = false;
          }
        }
      } else {
        if (Past_sec(INACTIVE_TIME_RFID, RFIDCheck.var)) {

          RFIDCheck.flag = true;
        }
    }*/
    }
    if (IN_OUT_MANUAL) {
      myManualDoorController.run(DEBUG);
      /* if (ManualDoorCheck.flag) {
         if (Past_mil(ManualDoorCheck.time, ManualDoorCheck.var)) {
           if (myManualDoorController.Read(DEBUG)) {
             myManualDoorController.Turn_on_light(DEBUG);
             if (myManualDoorController.getButtonOption()) {
               myCapacityManager.Add(DEBUG);
             }
             { myCapacityManager.Substract(DEBUG); }
           }
       }else{
       myCapacityManager.Substract(DEBUG);
   }
       } else {
         if (Past_mil(INACTIVE_TIME_MANUAL, ManualDoorCheck.var)) {
           myManualDoorController.Turn_off_light(DEBUG);
           ManualDoorCheck.flag = false;
         }
     }*/
    }
  }
}
