Ghostbusters Bargraph Sequence Library
A simple Arduino library for creating screen-accurate bargraph animations for a Ghostbusters Neutrona Wand prop, specifically designed for a 28-segment LED bargraph controlled by an HT16K33 driver.

This library was developed to be low-cost and easy to use, allowing makers to replicate several iconic firing and idle patterns.

IMPORTANT: Dependencies & Required Modifications
This project requires a modified version of the standard Adafruit HT16K33 library to function correctly.

1. Required Library: You must first install the "Adafruit GFX Library" and "Adafruit BusIO" library, and the "Adafruit LED Backpack Library" from the Arduino Library Manager.

2. Modification:
After installing, you must manually edit one of the library's files.

File to Edit: ht16k33.cpp

Change Required: [Please describe the exact change you made here. For example: "On line 57, change x=1 to x=0."]

Reason: This change is necessary to [Please describe the reason for the change here. For example: "correct the pixel addressing for this specific bargraph hardware."]

To simplify this process, a pre-modified version of ht16k33.cpp is included in the /modified_libraries folder of this repository. Please use it to replace the existing file in your Arduino libraries folder after installing the standard library.

Features
Multiple animation sequences, including idle, firing, and vent modes.

Non-blocking code to ensure smooth, responsive operation.

Easy configuration for both Common Anode and Common Cathode versions of the bargraph hardware.

Includes a full suite of example sketches to test hardware and demonstrate features.

Hardware Requirements
An Arduino-compatible microcontroller (e.g., Arduino Uno, Nano, ESP32).

A 28-segment LED bargraph.

An HT16K33 I2C LED driver breakout board.

Installation
Download: Click the "Code" button on this GitHub page and select "Download ZIP".

Install in Arduino IDE: Open your Arduino IDE, go to Sketch > Include Library > Add .ZIP Library..., and select the ZIP file you just downloaded.

Apply Modification: Follow the instructions in the "Dependencies & Required Modifications" section above.

Restart Arduino IDE: Close and reopen the Arduino IDE to ensure the library is properly indexed.

Basic Usage
1. Configure Your Hardware

Before using the library, you must configure it for your specific bargraph hardware.

Inside your main sketch folder, create a new file named config.h.

Add the following code to config.h, making sure to uncomment the line that matches your hardware:

// config.h
#ifndef CONFIG_H
#define CONFIG_H

// --- Bar Graph Hardware Type ---
// Please choose the line that matches your hardware.
const bargraph_hardware_t BARGRAPH_HARDWARE = BARGRAPH_COMMON_ANODE;
// const bargraph_hardware_t BARGRAPH_HARDWARE = BARGRAPH_COMMON_CATHODE;

#endif

2. Include and Initialize

In your main .ino sketch, include the library and create an instance of the BGSequence class.

#include "BGSequence.h"   // Must be included first!
#include "config.h"       // Your new configuration file
#include <Wire.h>
#include <HT16K33.h>

// Create an instance of the library
BGSequence BarGraph;

// This enum is needed to select animation modes
enum BarGraphSequences { START, ACTIVE, FIRE1, FIRE2, BGVENT };

void setup() {
  // Initialize the bargraph, passing in your hardware setting
  BarGraph.BGSeq(BARGRAPH_HARDWARE);

  // Set up the initial animation you want to run
  BarGraph.initiateVariables(START);
}

void loop() {
  // Continuously call the animation function in the main loop
  BarGraph.sequenceStart(millis());
}

3. Using the Examples

The best way to get started is to use the included example sketches. You can find them in the Arduino IDE under File > Examples > [Your Library Name].

Test_All_LEDs: The perfect first sketch to run. It will light up each LED one by one to confirm your wiring is correct.

Demo_[AnimationName]: A series of sketches that each loop a single animation, allowing you to see it in isolation.

Demo_Reel_All_Animations: A showcase sketch that cycles through every animation in the library.

Acknowledgements
This library is a modification of the original work by Mike Simone. His original repository can be found here: https://github.com/MikeS11/ProtonPack

The original project also gives reference credit to Eric Banker for the wand LED helper function.

Contributing
Contributions are welcome! If you have ideas for new animations or improvements, please feel free to open an issue or submit a pull request.

License
This project is licensed under the MIT License - see the LICENSE.md file for details.
