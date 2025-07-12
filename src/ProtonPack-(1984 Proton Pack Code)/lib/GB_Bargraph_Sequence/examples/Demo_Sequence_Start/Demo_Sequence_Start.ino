// ===================================================================================
// FILE: Demo_Sequence_Start.ino
// PURPOSE: This sketch demonstrates the "sequenceStart" animation in a
//          continuous loop. This is the "climb and drop" effect.
// ===================================================================================


#include "BGSequence.h"   // IMPORTANT: Include the library header first!
#include "config.h"       // Your custom configuration file
#include <Wire.h>
#include <HT16K33.h>

BGSequence BarGraph;

// This enum is required for the initiateVariables function
enum BarGraphSequences { START, ACTIVE, FIRE1, FIRE2, BGVENT };

void setup() {
  Serial.begin(9600);
  Serial.println("Starting 'sequenceStart' Demo...");

  // Initialize the bargraph library
  BarGraph.BGSeq(BARGRAPH_HARDWARE);
  
  // Initialize the variables for the START sequence
  BarGraph.initiateVariables(START); 
}

void loop() {
  // Continuously call the animation function in the loop
  BarGraph.sequenceStart(millis());
}
