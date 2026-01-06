// ===================================================================================
// FILE: Demo_Sequence_Fire2.ino
// PURPOSE: This sketch demonstrates the "sequenceFire2" animation in a
//          continuous loop.
// ===================================================================================


#include "BGSequence.h"   // IMPORTANT: Include the library header first!
#include "config.h"       // Your custom configuration file
#include <Wire.h>
#include <HT16K33.h>

BGSequence BarGraph;

enum BarGraphSequences { START, ACTIVE, FIRE1, FIRE2, BGVENT };

void setup() {
  Serial.begin(9600);
  Serial.println("Starting 'sequenceFire2' Demo...");

  BarGraph.BGSeq(BARGRAPH_HARDWARE);
  BarGraph.initiateVariables(FIRE2);
}

void loop() {
  BarGraph.sequenceFire2(millis());
}