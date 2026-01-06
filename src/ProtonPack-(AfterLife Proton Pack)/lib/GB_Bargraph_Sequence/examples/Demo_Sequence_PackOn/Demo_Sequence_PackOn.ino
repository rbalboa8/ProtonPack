// ===================================================================================
// FILE: Demo_Sequence_PackOn.ino
// PURPOSE: This sketch demonstrates the "sequencePackOn" animation in a
//          continuous loop. This is the "all on then drop" effect.
// ===================================================================================


#include "BGSequence.h"   // IMPORTANT: Include the library header first!
#include "config.h"       // Your custom configuration file
#include <Wire.h>
#include <HT16K33.h>

BGSequence BarGraph;

enum BarGraphSequences { START, ACTIVE, FIRE1, FIRE2, BGVENT };

void setup() {
  Serial.begin(9600);
  Serial.println("Starting 'sequencePackOn' Demo...");

  BarGraph.BGSeq(BARGRAPH_HARDWARE);
  BarGraph.initiateVariables(ACTIVE); // ACTIVE corresponds to sequencePackOn
}

void loop() {
  BarGraph.sequencePackOn(millis());
}
