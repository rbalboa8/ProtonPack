// ===================================================================================
// FILE: Demo_Sequence_Vent.ino
// PURPOSE: This sketch demonstrates the "sequenceVent" animation in a
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
  Serial.println("Starting 'sequenceVent' Demo...");

  BarGraph.BGSeq(BARGRAPH_HARDWARE);
  BarGraph.initiateVariables(BGVENT);
}

void loop() {
  BarGraph.sequenceVent(millis());
}