#include "Common.h"
#include "Dependencies.h"
#include "Functionalities.h"

bool Past_sec(uint32_t time, uint32_t &var);
bool Past_min(uint32_t time, uint32_t &var);
bool Past_mil(uint32_t time, uint32_t &var);

PROBE myProbe = PROBE();
CapacityManager myCapacityManager = CapacityManager(MAX_CAPACITY);
LDRController myLDR = LDRController(LDR_THRESHOLD);
PIRController myPIR = PIRController();
DHT_S myDHT = DHT_S();
EmergencyDoorController myEmergencyDoor = EmergencyDoorController();
ManualDoorController myManualDoorController = ManualDoorController();

/* ======================= Timers ======================= */

struct Timer {
  uint32_t time; // Time that must pass
  uint32_t var;  // Var to compare
};

Timer EmergencyDoorCheck;
Timer CapacityCheck;
Timer CorridorLightCheck;

/* ======================= Globals ======================= */

bool EmergencyDoorCheckFlag = false;
bool CapacityCheckFlag = false;

/* ======================================================= */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  EQUIPO::Setup(DEBUG);

  EmergencyDoorCheck.time = TIME_TO_CHECK_EMERGENCY_DOOR;

  CapacityCheck.time = TIME_TO_CHECK_CAPACITY;

  CorridorLightCheck.time = TIME_TO_CHECK_CORRIDOR_LIGHT;

  CapacityCheck.var = EmergencyDoorCheck.var = CorridorLightCheck.var =
      millis();

  if (SPECTS_BASIC) {
    if (CONTROL_EMERGERCY_DOOR) {
      myEmergencyDoor.Setup(DEBUG);
    }
    if (CONTROL_CAPACITY) {
      myCapacityManager.Setup(DEBUG);
    }
    if (CONTROL_SMART_CORRIDOR_LIGHT) {
      myPIR.Setup(DEBUG);
    }
    if (CONTROL_TEMP) {
      myProbe.Setup(DEBUG);
    }
    if (CONTROL_EXTERNAL_LIGHT) {
      myLDR.Setup(DEBUG);
    }
    if (CONTROL_HUMIDITY) {
      myDHT.Setup(DEBUG);
    }
  }
  if (SPECTS_EXTRA) {
    if (IN_OUT_BARRIER) {
    }
    if (IN_OUT_RFID) {
    }
    if (IN_OUT_MANUAL) {
      myManualDoorController.Setup(DEBUG);
    }
  }
}
uint8_t c = 0;
void loop() {
  // put your main code here, to run repeatedly:

  if (SPECTS_BASIC) {
    if (CONTROL_EMERGERCY_DOOR) {
      if (EmergencyDoorCheckFlag &&
          Past_mil(EmergencyDoorCheck.time, EmergencyDoorCheck.var)) {

        // Read the button

        if (DEBUG) {
          Serial.println(F("===== Puerta de emergencia abierta ====="));
        }

        EmergencyDoorCheckFlag = false;
      }
      if (!EmergencyDoorCheckFlag &&
          Past_mil(EmergencyDoorCheck.time * 2, EmergencyDoorCheck.var)) {
        EmergencyDoorCheckFlag = true;
      }
    }
    if (CONTROL_CAPACITY) {
      if (CapacityCheckFlag &&
          Past_mil(CapacityCheck.time, CapacityCheck.var)) {

        if (DEBUG) {
          Serial.println(F("===== Contador de aforo ====="));
        }

        // Here Read the buttons and do something

        CapacityCheckFlag = false;
      }

      if (!CapacityCheckFlag &&
          Past_mil(CapacityCheck.time * 2, CapacityCheck.var)) {

        CapacityCheckFlag = true;
      }
    }
    if (CONTROL_SMART_CORRIDOR_LIGHT) {
      if (Past_sec(CorridorLightCheck.time, CorridorLightCheck.var)) {

        // Read the button

        if (DEBUG) {
          Serial.println(F("===== Luz del pasillo ====="));
        }
      }
    }
    if (CONTROL_TEMP) {
    }
    if (CONTROL_EXTERNAL_LIGHT) {
    }
    if (CONTROL_HUMIDITY) {
    }
  }
  if (SPECTS_EXTRA) {
    if (IN_OUT_BARRIER) {
    }
    if (IN_OUT_RFID) {
    }
    if (IN_OUT_MANUAL) {
    }
  }
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
