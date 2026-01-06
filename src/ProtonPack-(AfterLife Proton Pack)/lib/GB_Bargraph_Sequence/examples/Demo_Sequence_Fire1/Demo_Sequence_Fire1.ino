// ===================================================================================
// FILE: Demo_Sequence_Fire1.ino
// PURPOSE: This sketch demonstrates the "sequenceFire1" animation in a
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
  Serial.println("Starting 'sequenceFire1' Demo...");

  BarGraph.BGSeq(BARGRAPH_HARDWARE);
  BarGraph.initiateVariables(FIRE1);
}

void loop() {
  BarGraph.sequenceFire1(millis());
}