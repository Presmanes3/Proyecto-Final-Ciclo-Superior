#include "Common.h"
#include "Dependencies.h"
#include "Functionalities.h"

bool Past_sec(uint32_t time, uint32_t &var);
bool Past_min(uint32_t time, uint32_t &var);
bool Past_mil(uint32_t time, uint32_t &var);
void Main_program();

TimeManager timeManager = TimeManager();
Agenda myAgenda = Agenda();
PROBE myProbe = PROBE();
CapacityManager myCapacityManager = CapacityManager(MAX_CAPACITY);
LDRController myLDR = LDRController(LDR_THRESHOLD);
PIRController myPIR = PIRController();
RFIDController myRFID = RFIDController(&myAgenda);
DHT_S myDHT = DHT_S();
EmergencyDoorController myEmergencyDoor = EmergencyDoorController();
ManualDoorController myManualDoorController = ManualDoorController();

/* ======================= Timers ======================= */

Timer EmergencyDoorCheck;
Timer CapacityCheck;
Timer CorridorLightCheck;
Timer TempCheck;
Timer LDRCheck;
Timer HumidityCheck;

Timer RFIDCheck;
Timer ManualDoorCheck;

/* ======================= Globals ======================= */

/* ======================================================= */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  EQUIPO::Setup(SERIAL_GUI);
  myAgenda.Setup(SERIAL_GUI);

  EmergencyDoorCheck.time = TIME_TO_CHECK_EMERGENCY_DOOR;
  CapacityCheck.time = TIME_TO_CHECK_CAPACITY;
  CorridorLightCheck.time = TIME_TO_CHECK_CORRIDOR_LIGHT;
  TempCheck.time = TIME_TO_CHECK_TEMP;
  LDRCheck.time = TIME_TO_CHECK_EXTERNAL_LIGHT;
  HumidityCheck.time = TIME_TO_CHECK_HUMIDITY;

  RFIDCheck.time = TIME_TO_CHECK_IN_OUT_RFID;
  ManualDoorCheck.time = TIME_TO_CHECK_IN_OUT_MANUAL;

  CapacityCheck.var = EmergencyDoorCheck.var = CorridorLightCheck.var =
      TempCheck.var = LDRCheck.var = HumidityCheck.var = RFIDCheck.var =
          ManualDoorCheck.var = millis();

  if (SPECTS_BASIC) {
    if (CONTROL_EMERGERCY_DOOR) {
      myEmergencyDoor.Setup(SERIAL_GUI);
    }
    if (CONTROL_CAPACITY) {
      myCapacityManager.Setup(SERIAL_GUI);
    }
    if (CONTROL_SMART_CORRIDOR_LIGHT) {
      myPIR.Setup(SERIAL_GUI);
    }
    if (CONTROL_TEMP) {
      myProbe.Setup(SERIAL_GUI);
    }
    if (CONTROL_EXTERNAL_LIGHT) {
      myLDR.Setup(SERIAL_GUI);
    }
    if (CONTROL_HUMIDITY) {
      myDHT.Setup(SERIAL_GUI);
    }
  }
  if (SPECTS_EXTRA) {
    if (IN_OUT_BARRIER) {
    }
    if (IN_OUT_RFID) {
      myRFID.Setup(SERIAL_GUI);
    }
    if (IN_OUT_MANUAL) {
      myManualDoorController.Setup(SERIAL_GUI);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // myRFID.Read(myAgenda.Contact_List, 2, DEBUG);

  Main_program();
}

bool Past_mil(uint32_t time, uint32_t &var) {
  if (millis() - var >= time) {
    var = millis();
    return true;
  }
  return false;
}
bool Past_sec(uint32_t time, uint32_t &var) {
  if (millis() - var >= (time * 1000)) {
    var = millis();
    return true;
  }
  return false;
}
bool Past_min(uint32_t time, uint32_t &var) {
  if (millis() - var >= (time * 60000)) {
    var = millis();
    return true;
  }
  return false;
}

void Main_program() {

  if (SPECTS_BASIC) {
    if (CONTROL_EMERGERCY_DOOR) {
      if (EmergencyDoorCheck.flag) {
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
      }
    }
    /*if (CONTROL_CAPACITY) {
      if (CapacityCheck.flag) {
        if (Past_mil(CapacityCheck.time, CapacityCheck.var)) {

          // Here Read the buttons and do something

          CapacityCheck.flag = false;
        }
      } else {
        if (Past_mil(INACTIVE_TIME_CAPACITY, CapacityCheck.var)) {
          CapacityCheck.flag = true;
        }
      }
  }*/
    if (CONTROL_SMART_CORRIDOR_LIGHT) {
      if (CorridorLightCheck.flag) {
        if (Past_sec(CorridorLightCheck.time, CorridorLightCheck.var)) {
          if (myPIR.Read(DEBUG)) {
            myPIR.Turn_on_light(DEBUG);
          }
        }
      } else {
        if (Past_min(INACTIVE_TIME_CORRIDOR_LIGHT, CorridorLightCheck.var)) {
          myPIR.Turn_off_light(DEBUG);
          CorridorLightCheck.flag = true;
        }
      }
    }
    if (CONTROL_TEMP) {
      if (TempCheck.flag) {
        if (Past_mil(TempCheck.time, TempCheck.var)) {
          myProbe.Read(DEBUG);
          myProbe.Show();
          TempCheck.flag = false;
        }
      } else {
        if (Past_min(INACTIVE_TIME_TEMPERATURE, TempCheck.var)) {
          TempCheck.flag = true;
        }
      }
    }
    if (CONTROL_EXTERNAL_LIGHT) {
      if (LDRCheck.flag) {
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
      }
    }
    if (CONTROL_HUMIDITY) {
      if (HumidityCheck.flag) {
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
    }
  }
  if (SPECTS_EXTRA) {
    if (IN_OUT_BARRIER) {
    }
    if (IN_OUT_RFID) {
      if (RFIDCheck.flag) {
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
      }
    }
    if (IN_OUT_MANUAL) {
      if (ManualDoorCheck.flag) {
        if (Past_mil(ManualDoorCheck.time, ManualDoorCheck.var)) {
          if (myManualDoorController.Read(DEBUG)) {
            myManualDoorController.Turn_on_light(DEBUG);
            if (myManualDoorController.getButtonOption()) {
              myCapacityManager.Add(DEBUG);
            }
            { myCapacityManager.Substract(DEBUG); }
          }
        }
      } else {
        if (Past_mil(INACTIVE_TIME_MANUAL, ManualDoorCheck.var)) {
          myManualDoorController.Turn_off_light(DEBUG);
          ManualDoorCheck.flag = false;
        }
      }
    }
  }
}
