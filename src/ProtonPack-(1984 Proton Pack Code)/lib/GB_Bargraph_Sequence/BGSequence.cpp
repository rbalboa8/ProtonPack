/*
    Ghostbusters Bargraph Sequences
    
    This is the source code for 5 separate bargraph sequence patterns for a ghostbusters neutrona wand
    Author Mike Simone - August 2020

    Modified 2025:
    - Added hardware mapping selection via pointer (activeMap) to support Common Anode/Cathode.
    - Applied GitHub Issue #1 fix (IndexSegment = 0 in Pack On).
    - Added testLed helper function for example sketches.
*/

#include "BGSequence.h"
#include <HT16K33.h>

// Initialize the external HT16K33 instance
HT16K33 bargraph = HT16K33();

// Constructor
BGSequence::BGSequence() {
  // Default to anode mapping
  activeMap = barGraph_anode;
}

void BGSequence::BGSeq(bargraph_hardware_t hardwareType)
{
  // Select the correct coordinate map based on hardware type from config.h
  if (hardwareType == BARGRAPH_COMMON_CATHODE) {
    activeMap = barGraph_cathode;
  } else {
    activeMap = barGraph_anode;
  }

  /* Initiate the HT16K33 */
  bargraph.init(0x70);
  delay(1000);
  bargraph.setBrightness(10);
}

/*
    Firing Routine 1 - Initiation (Reset indexes)
*/
void BGSequence::initiateVariables(uint8_t BGMODE)
{
  switch (BGMODE)
  {
    case 0:
      IndexSegment = 0;
      lastUpdateBG = 0;
      IntervalBG = 60;
      DirectionBG = FORWARD;
      break;
    case 1:
      IndexSegment = 27;
      lastUpdateBG = 0;
      IntervalBG = 20;
      DirectionBG = FORWARD;
      break;
    case 2:
      IndexSegment = 0;
      lastUpdateBG = 0;
      IntervalBG = 50;
      DirectionBG = FORWARD;
      break;
    case 3:
      IndexSegment = 0;
      lastUpdateBG = 0;
      IntervalBG = 50;
      DirectionBG = FORWARD;
      break;
    case 4:
      IndexSegment = 27;
      lastUpdateBG = 0;
      IntervalBG = 75;
      lastUpdateVENT = 0;
      IntervalVENT = 2000;
      startVent = true;
      DirectionBG = FORWARD;
      break;
  }
}

void BGSequence::changeInterval(uint8_t NewInterval)
{
  IntervalBG = NewInterval;
}

/*
    Fire 1 Sequence
*/
void BGSequence::sequenceFire1(unsigned long currentMillis)
{
  if ((currentMillis - lastUpdateBG) > IntervalBG)
  {
    lastUpdateBG = currentMillis;
    for (int i = 0; i < 28; i++)
    {
      if (pgm_read_byte_near(BGLEDStateFire1[IndexSegment] + i) == 1)
      {
        drawBarGraph(activeMap[i][0], activeMap[i][1], 1);
      }
      if (pgm_read_byte_near(BGLEDStateFire1[IndexSegment]+ i) == 0)
      {
        if (DirectionBG == FORWARD && pgm_read_byte_near(BGLEDStateFire1[IndexSegment - 1]+ i) == 1 )
        {
          drawBarGraph(activeMap[i][0], activeMap[i][1], 0);
        }
        else if (DirectionBG == REVERSE && pgm_read_byte_near(BGLEDStateFire1[IndexSegment + 1]+ i) == 1)
        {
          drawBarGraph(activeMap[i][0], activeMap[i][1], 0);
        }
      }
    }
    if (IndexSegment >= 12) { DirectionBG = REVERSE; }
    else if (IndexSegment <= 0) { DirectionBG = FORWARD; }
    
    if (DirectionBG == FORWARD) { IndexSegment++; }
    else { IndexSegment--; }
    
    bargraph.write();
  }
}

/*
    Firing Routine 2
*/
void BGSequence::sequenceFire2(unsigned long currentMillis)
{
  if ((currentMillis - lastUpdateBG) > IntervalBG)
  {
    lastUpdateBG = currentMillis;
    for (int i = 0; i < 28; i++)
    {
      if (pgm_read_byte_near(BGLEDStateFire2[IndexSegment] + i) == 1)
      {
        if (pgm_read_byte_near(BGLEDStateFire2[IndexSegment - 1] + i) == 0 || (IndexSegment == 0 || IndexSegment == 1 || IndexSegment == 2))
        {
          drawBarGraph(activeMap[i][0], activeMap[i][1], 1);
        }
      }
      if (pgm_read_byte_near(BGLEDStateFire2[IndexSegment] + i) == 0 )
      {
        if (pgm_read_byte_near(BGLEDStateFire2[IndexSegment - 1] + i) == 1 || IndexSegment == 0)
        {
          drawBarGraph(activeMap[i][0], activeMap[i][1], 0);
        }
      }
    }
    if (IndexSegment >= 15) { IndexSegment = 0; }
    else { IndexSegment++; }
    
    bargraph.write();
  }
}

/*
    Starting Routine
*/
void BGSequence::sequenceStart(unsigned long currentMillis)
{
  if ((currentMillis - lastUpdateBG) > IntervalBG)
  {
    lastUpdateBG = currentMillis;
    if (DirectionBG == FORWARD)
    {
      for (int i = 0; i <= 27; i++)
      {
        if (i == IndexSegment ) { drawBarGraph(activeMap[i][0], activeMap[i][1], 1); }
      }
    }
    else
    {
      for (int i = 0; i <= 27; i++)
      {
        if (i == IndexSegment ) { drawBarGraph(activeMap[i + 1][0], activeMap[i + 1][1], 0); }
      }
    }

    if (IndexSegment == 27) { DirectionBG = REVERSE; }
    if (IndexSegment == 0) { DirectionBG = FORWARD; }

    if (DirectionBG == FORWARD) { IndexSegment++; }
    else { IndexSegment--; }

    bargraph.write();
  }
}

/*
    Pack on Routine (Wand and Pack are both on)
*/
void BGSequence::sequencePackOn(unsigned long currentMillis)
{
  if ((currentMillis - lastUpdateBG) > IntervalBG)
  {
    lastUpdateBG = currentMillis;
    if (IndexSegment == 15)
    {
      for (int i = 0; i < 28; i++) { drawBarGraph(activeMap[i][0], activeMap[i][1], 1); }
      // FIXED: Reset index to 0 instead of 27 per GitHub Issue #1
      IndexSegment = 0; 
    }
    for (int i = 15; i <= 27; i++)
    {
      if (i == IndexSegment ) { drawBarGraph(activeMap[i][0], activeMap[i][1], 0); }
    }
    IndexSegment--;
    bargraph.write();
  }
}

/*
    Vent Routine
*/
void BGSequence::sequenceVent(unsigned long currentMillis)
{
  if (startVent == true)
  {
    lastUpdateVENT = currentMillis;
    startVent = false;
    for (int i = 0; i < 28; i++) { drawBarGraph(activeMap[i][0], activeMap[i][1], 1); }
    bargraph.write();
  }
  else
  {
    if ((currentMillis - lastUpdateVENT) > IntervalVENT)
    {
      if ((currentMillis - lastUpdateBG) > IntervalBG)
      {
        lastUpdateBG = currentMillis;
        for (int i = 0; i <= 27; i++)
        {
          if (i == IndexSegment ) { drawBarGraph(activeMap[i][0], activeMap[i][1], 0); }
        }
        IndexSegment--;
        bargraph.write();
      }
    }
  }
}

/*
    Shutdown Routine
*/
void BGSequence::sequenceShutdown(unsigned long currentMillis)
{
  if ((currentMillis - lastUpdateBG) > IntervalBG)
  {
    lastUpdateBG = currentMillis;
    drawBarGraph(activeMap[IndexSegment+1 ][0], activeMap[IndexSegment+1 ][1], 0);
    
    // Fix: Unsigned underflow protection
    if (IndexSegment < 255) {
      IndexSegment--;
      bargraph.write();
    }
  }
}

void BGSequence::clearLEDs()
{
  for (int i = 0; i <= 27; i++) { drawBarGraph(activeMap[i][0], activeMap[i][1], 0); }
  bargraph.write();
}

void BGSequence::drawBarGraph( uint8_t row, uint8_t col, uint8_t val )
{
  bargraph.setPixel(row, col, val);
}

void BGSequence::testLed(uint8_t led, uint8_t val) {
  if (led < 28) {
    drawBarGraph(activeMap[led][0], activeMap[led][1], val);
    bargraph.write();
  }
}