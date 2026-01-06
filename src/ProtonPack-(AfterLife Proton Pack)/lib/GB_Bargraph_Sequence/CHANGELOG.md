Changelog
All notable changes to this project will be documented in this file.

The format is based on Keep a Changelog,
and this project adheres to Semantic Versioning.

[Unreleased]
Added

(List any new features you are currently working on for the next release here)

[1.1.0] - 2025-07-04
Added

Hardware Flexibility: The library now supports both Common Anode and Common Cathode versions of the 28-segment bargraph.

Easy Configuration: A config.h file has been added to allow users to easily select their hardware type without editing the core library code.

Example Sketches: A full suite of example sketches has been created to help users test their hardware and understand library functions. This includes:

Test_All_LEDs.ino for wiring validation.

Individual demo sketches for each animation (Demo_Sequence_Start, Demo_Sequence_PackOn, etc.).

A Demo_Reel_All_Animations.ino to showcase all features.

testLed() Function: A new public helper function was added to the library to make it simple to test individual LEDs.

Changed

Initialization: The BGSeq() initialization function in the library now requires a hardware type parameter (e.g., BARGRAPH_COMMON_ANODE) to be passed to it.

Internal Logic: The library's internal code was refactored to use a pointer to switch between different hardware mapping arrays, ensuring seamless compatibility.

Fixed

Corrected an issue in the sequencePackOn animation where the index did not reset properly, causing the animation to fail after the first loop. (Addresses Issue #1 from the original repository).


[1.0.0] - 2020-08-15
Added

Initial release of the library by Mike Simone.

Core animation sequences: sequenceStart, sequencePackOn, sequenceFire1, sequenceFire2, sequenceVent.
