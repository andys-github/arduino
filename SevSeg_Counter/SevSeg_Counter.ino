#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

void setup() {
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {A3, A1, 11, 9, 6, A5, 2, 13};
  bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = true; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
}

void loop() {
  for(int i = 0; i < 10; i++) {
    sevseg.setNumber(i, 0);
    delay(500);
    sevseg.refreshDisplay();
  }

  char* chars_ptr = "abcdef";
  for(int i = 0; i < 6; i++) {
    sevseg.setChars(chars_ptr + i);
    delay(500);
    sevseg.refreshDisplay();
  }
}

/// END ///
