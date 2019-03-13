#include "Common.h"
#include "Dependencies.h"
#include "Functionalities.h"

bool Past_sec(uint32_t time, uint32_t &var);
bool Past_min(uint32_t time, uint32_t &var);
bool Past_mil(uint32_t time, uint32_t &var);
void Main_program();

PROBE myProbe = PROBE();
CapacityManager myCapacityManager = CapacityManager(MAX_CAPACITY);
LDRController myLDR = LDRController(LDR_THRESHOLD);
PIRController myPIR = PIRController();
RFIDController myRFID = RFIDController();
DHT_S myDHT = DHT_S();
EmergencyDoorController myEmergencyDoor = EmergencyDoorController();
ManualDoorController myManualDoorController = ManualDoorController();

/* ======================= Timers ======================= */

struct Timer {
  uint32_t time; // Time that must pass
  uint32_t var;  // Var to compare
  bool flag = true;
};

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
  AGENDA::Setup(SERIAL_GUI);

  EmergencyDoorCheck.time = TIME_TO_CHECK_EMERGENCY_DOOR;

  CapacityCheck.time = TIME_TO_CHECK_CAPACITY;

  CorridorLightCheck.time = TIME_TO_CHECK_CORRIDOR_LIGHT;

  RFIDCheck.time = TIME_TO_CHECK_IN_OUT_RFID;

  CapacityCheck.var = EmergencyDoorCheck.var = CorridorLightCheck.var =
      RFIDCheck.var = millis();

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
  // myRFID.Read(AGENDA::Contact_List, 2, DEBUG);

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
      if (EmergencyDoorCheck.flag &&
          Past_mil(EmergencyDoorCheck.time, EmergencyDoorCheck.var)) {
        // Read the button
        if (myEmergencyDoor.Read(DEBUG)) {

          myEmergencyDoor.Turn_on_light(DEBUG);
          EmergencyDoorCheck.flag = false;
        }
      }
      if (!EmergencyDoorCheck.flag && Past_sec(5, EmergencyDoorCheck.var)) {
        myEmergencyDoor.Turn_off_light(DEBUG);
        EmergencyDoorCheck.flag = true;
      }
    }
    if (CONTROL_CAPACITY) {
      if (CapacityCheck.flag &&
          Past_mil(CapacityCheck.time, CapacityCheck.var)) {

        // Here Read the buttons and do something

        CapacityCheck.flag = false;
      }

      if (!CapacityCheck.flag &&
          Past_mil(CapacityCheck.time * 2, CapacityCheck.var)) {

        CapacityCheck.flag = true;
      }
    }
    if (CONTROL_SMART_CORRIDOR_LIGHT) {
      if (CorridorLightCheck.flag &&
          Past_sec(CorridorLightCheck.time, CorridorLightCheck.var)) {
        if (myPIR.Read(DEBUG)) {
          myPIR.Turn_on_light(DEBUG);
        }
      }
      if (!CorridorLightCheck.flag && Past_min(1, CorridorLightCheck.var)) {
        myPIR.Turn_off_light(DEBUG);
        CorridorLightCheck.flag = true;
      }
    }
    if (CONTROL_TEMP) {
      if (TempCheck.flag && Past_mil(TempCheck.time, TempCheck.var)) {
        myProbe.Read(DEBUG);
        myProbe.Show();
        TempCheck.flag = false;
      }
      if (!TempCheck.flag && Past_sec(30, TempCheck.var)) {
        TempCheck.flag = true;
      }
    }
    if (CONTROL_EXTERNAL_LIGHT) {
      if (LDRCheck.flag && Past_mil(LDRCheck.time, LDRCheck.var)) {
        if (myLDR.Read(DEBUG)) {
          myLDR.Turn_on_light(DEBUG);
          LDRCheck.flag = false;
        }
      }
      if (!LDRCheck.flag && Past_min(1, LDRCheck.var)) {
        myLDR.Turn_off_light(DEBUG);
        LDRCheck.flag = true;
      }
    }
    if (CONTROL_HUMIDITY) {
    }
  }
  if (SPECTS_EXTRA) {
    if (IN_OUT_BARRIER) {
    }
    if (IN_OUT_RFID) {
      if (RFIDCheck.flag && Past_mil(RFIDCheck.time, RFIDCheck.var)) {
        if (DEBUG) {
          Serial.println(F("===== Leyendo RFID Sensor ====="));
        }
        if (myRFID.Read(AGENDA::Contact_List, 2, SERIAL_GUI)) {
          RFIDCheck.flag = false;
        }
      }
      if (!RFIDCheck.flag && Past_sec(5, RFIDCheck.var)) {

        RFIDCheck.flag = true;
      }
    }
    if (IN_OUT_MANUAL) {
      if (ManualDoorCheck.flag &&
          Past_mil(ManualDoorCheck.time, ManualDoorCheck.var)) {
        if (myManualDoorController.Read(DEBUG)) {
        }
      }
      if (!ManualDoorCheck.flag &&
          Past_mil(ManualDoorCheck.time * 2, ManualDoorCheck.var)) {
        ManualDoorCheck.flag = false;
      }
    }
  }
}
