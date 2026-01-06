/*
    Ghostbusters Bargraph Sequences - Implementation
    
    This file handles the animation logic and hardware mapping.
    Modified to avoid naming collisions with GBLEDPatternsJewel.
*/

#include "BGSequence.h"
#include <HT16K33.h>

// Instantiate the HT16K33 object. 
// This resolves the "undefined reference" error by creating the actual variable in memory.
HT16K33 bargraph = HT16K33();

// Constructor
BGSequence::BGSequence() {
  activeMap = barGraph_anode;
}

void BGSequence::BGSeq(bargraph_hardware_t hardwareType) {
  // Select mapping based on hardware configuration
  if (hardwareType == BARGRAPH_COMMON_CATHODE) {
    activeMap = barGraph_cathode;
  } else {
    activeMap = barGraph_anode;
  }

  bargraph.init(0x70);
  delay(1000);
  bargraph.setBrightness(10);
}

void BGSequence::initiateVariables(uint8_t BGMODE) {
  // Clear display before switching modes to prevent overlapping segments
  clearLEDs();
  
  switch (BGMODE) {
    case 0: // START
      IndexSegment = 0;
      lastUpdateBG = 0;
      IntervalBG = 60;
      DirectionBG = BG_FORWARD;
      break;
    case 1: // PACK ON
      IndexSegment = 27;
      lastUpdateBG = 0;
      IntervalBG = 20;
      DirectionBG = BG_FORWARD;
      break;
    case 2: // FIRE 1
      IndexSegment = 0;
      lastUpdateBG = 0;
      IntervalBG = 50;
      DirectionBG = BG_FORWARD;
      break;
    case 3: // FIRE 2
      IndexSegment = 0;
      lastUpdateBG = 0;
      IntervalBG = 50;
      DirectionBG = BG_FORWARD;
      break;
    case 4: // VENT
      IndexSegment = 27;
      lastUpdateBG = 0;
      IntervalBG = 75;
      lastUpdateVENT = 0;
      IntervalVENT = 2000;
      startVent = true;
      DirectionBG = BG_FORWARD;
      break;
  }
}

void BGSequence::changeInterval(uint8_t NewInterval) {
  IntervalBG = NewInterval;
}

void BGSequence::sequenceStart(unsigned long currentMillis) {
  if ((currentMillis - lastUpdateBG) > IntervalBG) {
    lastUpdateBG = currentMillis;
    
    if (DirectionBG == BG_FORWARD) {
      if (IndexSegment < 28) {
        drawBarGraph(activeMap[IndexSegment][0], activeMap[IndexSegment][1], 1);
      }
    } else {
      // Turn off LEDs as it drops
      if (IndexSegment < 27) {
        drawBarGraph(activeMap[IndexSegment + 1][0], activeMap[IndexSegment + 1][1], 0);
      } else if (IndexSegment == 27) {
        drawBarGraph(activeMap[27][0], activeMap[27][1], 1); 
      }
    }

    // Logic for bouncing the animation
    if (IndexSegment >= 27) DirectionBG = BG_REVERSE;
    if (IndexSegment <= 0) DirectionBG = BG_FORWARD;

    if (DirectionBG == BG_FORWARD) IndexSegment++; else IndexSegment--;
    bargraph.write();
  }
}

void BGSequence::sequenceFire1(unsigned long currentMillis) {
  if ((currentMillis - lastUpdateBG) > IntervalBG) {
    lastUpdateBG = currentMillis;
    
    // Draw the full frame from PROGMEM to ensure segments turn off correctly
    for (int i = 0; i < 28; i++) {
      bool state = pgm_read_byte_near(BGLEDStateFire1[IndexSegment] + i);
      drawBarGraph(activeMap[i][0], activeMap[i][1], state);
    }
    
    if (IndexSegment >= 13) DirectionBG = BG_REVERSE;
    else if (IndexSegment <= 0) DirectionBG = BG_FORWARD;
    
    if (DirectionBG == BG_FORWARD) IndexSegment++; else IndexSegment--;
    bargraph.write();
  }
}

void BGSequence::sequenceFire2(unsigned long currentMillis) {
  if ((currentMillis - lastUpdateBG) > IntervalBG) {
    lastUpdateBG = currentMillis;
    
    for (int i = 0; i < 28; i++) {
      bool state = pgm_read_byte_near(BGLEDStateFire2[IndexSegment] + i);
      drawBarGraph(activeMap[i][0], activeMap[i][1], state);
    }
    
    if (IndexSegment >= 15) IndexSegment = 0; else IndexSegment++;
    bargraph.write();
  }
}

void BGSequence::sequencePackOn(unsigned long currentMillis) {
  if ((currentMillis - lastUpdateBG) > IntervalBG) {
    lastUpdateBG = currentMillis;
    
    // Reset condition: Turn all on then start dropping
    if (IndexSegment <= 0) {
      for (int i = 0; i < 28; i++) drawBarGraph(activeMap[i][0], activeMap[i][1], 1);
      IndexSegment = 27;
    }
    
    if (IndexSegment >= 0 && IndexSegment < 28) {
      drawBarGraph(activeMap[IndexSegment][0], activeMap[IndexSegment][1], 0);
    }
    
    IndexSegment--;
    bargraph.write();
  }
}

void BGSequence::sequenceVent(unsigned long currentMillis) {
  if (startVent == true) {
    lastUpdateVENT = currentMillis;
    startVent = false;
    for (int i = 0; i < 28; i++) drawBarGraph(activeMap[i][0], activeMap[i][1], 1);
    bargraph.write();
  } else {
    if ((currentMillis - lastUpdateVENT) > IntervalVENT) {
      if ((currentMillis - lastUpdateBG) > IntervalBG) {
        lastUpdateBG = currentMillis;
        if (IndexSegment >= 0 && IndexSegment < 28) {
           drawBarGraph(activeMap[IndexSegment][0], activeMap[IndexSegment][1], 0);
        }
        IndexSegment--;
        if (IndexSegment < 0) IndexSegment = 0;
        bargraph.write();
      }
    }
  }
}

void BGSequence::sequenceShutdown(unsigned long currentMillis) {
  if ((currentMillis - lastUpdateBG) > IntervalBG) {
    lastUpdateBG = currentMillis;
    if (IndexSegment >= -1 && IndexSegment < 27) {
       drawBarGraph(activeMap[IndexSegment + 1][0], activeMap[IndexSegment + 1][1], 0);
    }
    IndexSegment--;
    bargraph.write();
  }
}

void BGSequence::clearLEDs() {
  for (int i = 0; i < 28; i++) drawBarGraph(activeMap[i][0], activeMap[i][1], 0);
  bargraph.write();
}

void BGSequence::drawBarGraph(uint8_t row, uint8_t col, uint8_t val) {
  bargraph.setPixel(row, col, val);
}

void BGSequence::testLed(uint8_t led, uint8_t val) {
  if (led < 28) {
    drawBarGraph(activeMap[led][0], activeMap[led][1], val);
    bargraph.write();
  }
}