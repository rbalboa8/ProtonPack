// ===================================================================================
//
//          Bargraph Library Example Sketches
//
// This file contains a collection of example sketches for the BGSequence library.
// Each sketch is designed to be run independently to test different
// features of the library and to help users validate their hardware wiring.
//
// Instructions:
// 1. Create the "config.h" file as previously discussed.
// 2. Copy the code for the sketch you want to test into a new Arduino sketch file.
// 3. Ensure the BGSequence library is correctly installed.
// 4. Upload and run the sketch.
//
// ===================================================================================


// ===================================================================================
// FILE: Test_All_LEDs.ino (Corrected Version)
// PURPOSE: This sketch tests the wiring of the bargraph by turning on each of the/Users/rbalboa8/Documents/Arduino/libraries/GB_Bargraph_Sequence/BGSequence.cpp
//          28 LEDs one by one, in sequence. It's the best way to confirm that
//          every LED is connected correctly and that the mapping is right.
// ===================================================================================


#include "BGSequence.h"   // IMPORTANT: Include the library header first!
#include "config.h"       // Your custom configuration file
#include <Wire.h>         // Required for I2C communication
#include <HT16K33.h>      // The driver library for the bargraph

// Create an instance of the library
BGSequence BarGraph;

// Define a delay time in milliseconds between each LED lighting up
const int testDelay = 100;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting LED Wiring Test...");

  // Initialize the bargraph library using the setting from config.h
  BarGraph.BGSeq(BARGRAPH_HARDWARE);

  Serial.println("Bargraph Initialized. Starting sequence...");
}

void loop() {
  // Loop through all 28 segments of the bargraph
  for (int i = 0; i < 28; i++) {
    Serial.print("Testing LED: ");
    Serial.println(i);

    // Turn the current LED ON
    BarGraph.testLed(i, 1); // Use the new testLed function

    delay(testDelay); // Wait for a moment

    // Turn the current LED OFF
    BarGraph.testLed(i, 0); // Use the new testLed function
  }

  // Add a longer pause before the whole sequence repeats
  delay(1000);
}






// ===================================================================================
// FILE: Demo_Sequence_PackOn.ino
// PURPOSE: This sketch demonstrates the "sequencePackOn" animation in a
//          continuous loop. This is the "all on then drop" effect.
// ===================================================================================

/*
#include "config.h"
#include <Wire.h>
#include <HT16K33.h>
#include "BGSequence.h"

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
*/


// ===================================================================================
// FILE: Demo_Sequence_Fire1.ino
// PURPOSE: This sketch demonstrates the "sequenceFire1" animation in a
//          continuous loop.
// ===================================================================================

/*
#include "config.h"
#include <Wire.h>
#include <HT16K33.h>
#include "BGSequence.h"

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
*/


// ===================================================================================
// FILE: Demo_Sequence_Fire2.ino
// PURPOSE: This sketch demonstrates the "sequenceFire2" animation in a
//          continuous loop.
// ===================================================================================

/*
#include "config.h"
#include <Wire.h>
#include <HT16K33.h>
#include "BGSequence.h"

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
*/


// ===================================================================================
// FILE: Demo_Sequence_Vent.ino
// PURPOSE: This sketch demonstrates the "sequenceVent" animation in a
//          continuous loop.
// ===================================================================================

/*
#include "config.h"
#include <Wire.h>
#include <HT16K33.h>
#include "BGSequence.h"

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
*/


// ===================================================================================
// FILE: Demo_Reel_All_Animations.ino
// PURPOSE: This sketch runs all the available animations one after another,
//          each for a set duration, and then loops. It's a great way to
//          showcase the full capabilities of the library.
// ===================================================================================

/*
#include "config.h"
#include <Wire.h>
#include <HT16K33.h>
#include "BGSequence.h"

BGSequence BarGraph;

enum BarGraphSequences { START, ACTIVE, FIRE1, FIRE2, BGVENT };

// How long to display each animation in milliseconds
const unsigned long DEMO_DURATION = 10000; // 10 seconds

// Variables to keep track of the demo state
int currentDemo = 0;
unsigned long demoStartTime;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting Full Demo Reel...");

  BarGraph.BGSeq(BARGRAPH_HARDWARE);
  
  // Start the timer for the first demo
  demoStartTime = millis();
  // Set up the first animation
  setupNextDemo();
}

void loop() {
  // Check if it's time to switch to the next animation
  if (millis() - demoStartTime > DEMO_DURATION) {
    currentDemo++; // Move to the next demo index
    
    // If we've gone past the last demo, loop back to the first
    if (currentDemo > 4) { // We have 5 demos, indexed 0-4
      currentDemo = 0;
    }
    
    // Set up the next demo animation
    setupNextDemo();
    // Reset the timer
    demoStartTime = millis();
  }

  // Run the current animation based on the demo index
  switch (currentDemo) {
    case 0:
      BarGraph.sequenceStart(millis());
      break;
    case 1:
      BarGraph.sequencePackOn(millis());
      break;
    case 2:
      BarGraph.sequenceFire1(millis());
      break;
    case 3:
      BarGraph.sequenceFire2(millis());
      break;
    case 4:
      BarGraph.sequenceVent(millis());
      break;
  }
}

// A helper function to initialize the variables for the next demo
void setupNextDemo() {
  Serial.print("Now showing demo: ");
  Serial.println(currentDemo);
  
  // Clear the display before starting the next animation
  BarGraph.clearLEDs();
  
  switch (currentDemo) {
    case 0:
      BarGraph.initiateVariables(START);
      break;
    case 1:
      BarGraph.initiateVariables(ACTIVE);
      break;
    case 2:
      BarGraph.initiateVariables(FIRE1);
      break;
    case 3:
      BarGraph.initiateVariables(FIRE2);
      break;
    case 4:
      BarGraph.initiateVariables(BGVENT);
      break;
  }
}
*/
