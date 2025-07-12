// ===================================================================================
// FILE: Demo_Reel_All_Animations.ino
// PURPOSE: This sketch runs all the available animations one after another,
//          each for a set duration, and then loops. It's a great way to
//          showcase the full capabilities of the library.
// ===================================================================================


#include "BGSequence.h"   // IMPORTANT: Include the library header first!
#include "config.h"       // Your custom configuration file
#include <Wire.h>
#include <HT16K33.h>

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