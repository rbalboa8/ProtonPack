[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![Twitter][Twitter-shield]][Twitter-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/MikeS11/ProtonPack">
    <img src="README_Images/MikeS11_Logo.jpg?raw=true" alt="Logo" width="180" height="200">
  </a>

  <h3 align="center">GhostKitty Proton Pack</h3>

  <p align="center">
  This is my contribution to the GB community. This project adds a bit more movie / game accuracy but also a little fun :)

<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Built With](#Build-Requirements)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Wand Configuration](#wand-configuration)  
* [License](#license)
* [Contact](#contact)
* [Acknowledgements](#acknowledgements)

<!-- ABOUT THE PROJECT -->
## About The Project

<div align="center">
  YouTube Video<br />
  <a href="https://www.youtube.com/watch?v=9ePM4p-J3tE"><img src="https://img.youtube.com/vi/9ePM4p-J3tE/0.jpg" alt="GhostKitty Proton Pack"></a>  

Original Prototype <br />
<img src="README_Images/ArduinoPrototype.jpg?raw=true" alt="Prototype" width="640" height="480"></p>

Afterlife Cyclotron 40 segment LED ring<br />
<img src="README_Images/AfterLifeCyclotron.jpg?raw=true" alt="Prototype" width="504"  height="442"></p>
</div>

I want this to be a source for anyone to use to create their own proton pack kits for as cheap as possible and still include all the features for a rumble motor, 2 firing mechanisms, all functioning LEDs in the wand, pack themes, full 28 segment bar graph, and an output for a vent kit.

**Current Themes for the pack:**
* []() Movie
* []() Stasis / Afterlife
* []() Slime
* []() Meson
* []() Christmas!
* []() *Future* Halloween

### Getting Started

### Build Requirements:

* []() 1 - Arduino Nano (Amazon)  
* []() 1 - DFPlayer Mini (Be aware that some of the knock offs do not perform correctly, reference to the busy pin may not work) (Digikey Only)
* []() 1 - Any amplifing circuit (Currently testing an Adafruit Stereo 20W Class D Audio Amplifier - MAX9744)  (Amazon, Digikey)
* []() 1 - LED Matrix Driver - HT16K33 Breakout (for the bar graph) (Amazon, Digikey)
* []() 1 - 28 segment bargraph (barmeter.com, ebay is your best option)
* []() 1 - Pack of neopixels or equivalent WS2812B ( Vent and wand LEDs) (Amazon)
* []() 1 - LED strip (Powercell)  (Amazon)
* []() 1 - Adafruit Jewel - Wand Tip (WAs looking at the Pixie but there is a concern of its overhead requirements when working with normal WS2812B's, and they can not be chained together with WS2812B's) (Amazon, Digikey)
* []() 1 - 40 Segment LED ring or LED strip (WS2812B's) - Afterlife Cyclotron LED
* []() Pack of 24 awg stranded cable (Amazon) - To keep things clean you might want to look at ribbon cables or multi conductor cables.
* []() For circuit noise filtering, I would add a 1000uF electrolytic capacitors closes to the neopixels, and a 470 Ohm resistor before the first led of the strip (This is recommended by Adafruit as well). I would recommend one 1000uF capacitor for the wand to filter out noise from both the bargraph and the neopixels. (See Diagram)
* []() If you are printing the PCB you will need a RJ45 Connector, 2.54mm JST Connectors, 2.54mm Dupont Connectors, 1 MP1584EN Buck Converter, 7805 Voltage regulator, 2 1k Ohm resistors, and some 0.1 uF and 0.33 uF ceramic capacitors. Additionally for the wand, 1000uF capacitor, a 1N4001 diode and a transistor.

### Prerequisites

You are going to need to install the following libraries:

**For the Audio DFPlayer Player:**
* []() SoftwareSerial.h
* []() DFPlayerMini_Fast.h

**For the WS2812B / NeoPixel LEDs**
* []() Adafruit_NeoPixel.h

**Custom Libraries for the Powercell / Cyclotron / Bargraph Animiations**
* []() GBLEDPatternsJewel.h
* []() BGSequence.h

**Sound Files for the DFPlayer or Alternative Player**

<a href="https://mega.nz/file/R5sWzCha#zm4DIskyvmF08JNp8MnOAEqCDmNe2MSCN6wtFMExKlU">Here are some sound files I found online or mixed myself</a>


### Wand Configuration

<p align="center">
<img src="README_Images/WandLEDs.jpg?raw=true" alt="Wand LEDs"></p>
<p align="center">
<img src="README_Images/WandSwitches.jpg?raw=true" alt="Wand Switches"></p>
<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request


<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Mike Simone - [@mikesimone3](https://twitter.com/mikesimone3)

Project Link: [https://github.com/MikeS11/ProtonPack](https://github.com/MikeS11/ProtonPack)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

* []() Eric Banker for the for the wonder work completed on his Arduino project. (a couple of his functions are referenced in this project)
* []()
* []()



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/MikeS11/ProtonPack.svg?style=flat-square
[contributors-url]: https://github.com/MikeS11/ProtonPack/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/MikeS11/ProtonPack.svg?style=flat-square
[forks-url]: https://github.com/MikeS11/ProtonPack/network/members
[stars-shield]: https://img.shields.io/github/stars/MikeS11/ProtonPack.svg?style=flat-square
[stars-url]: https://github.com/MikeS11/ProtonPack/stargazers
[issues-shield]: https://img.shields.io/github/issues/MikeS11/ProtonPack.svg?style=flat-square
[issues-url]: https://github.com/MikeS11/ProtonPack/issues
[license-shield]: https://img.shields.io/github/license/MikeS11/ProtonPack.svg?style=flat-square
[license-url]: https://github.com/MikeS11/ProtonPack/blob/master/LICENSE.txt
[twitter-shield]: https://img.shields.io/badge/-Twitter-black.svg?style=flat-square&logo=Twitter&colorB=555
[twitter-url]: https://Twitter.com/mikesimone3
[product-screenshot]: README_Images/screenshot.png
