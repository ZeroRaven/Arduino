
[![Arduino CI](https://github.com/RobTillaart/PulsePattern/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/PulsePattern/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/PulsePattern/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/PulsePattern/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/PulsePattern/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/PulsePattern/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/PulsePattern.svg?maxAge=3600)](https://github.com/RobTillaart/PulsePattern/releases)


# PulsePattern

Arduino Library to generate repeating pulse patterns **AVR ONLY**.


## Description

This is an **experimental** library to generate pulse patterns by means of an Arduino UNO.
As the library uses **AVR hardware timers** it is definitely **NOT** working for ESP
or other non-AVR processors.

The library uses timer1 for the timing of the pulses.
Therefore the class is implemented with a static instance called PPO.
Still by calling **init()** one can change all parameters of the process.
One should note that calling **init()** forces the timer to stop.

The timer code is based upon the website of Nick Gammon which
holds quite a lot of good solid material (Thanks Nick!).
https://gammon.com.au/forum/bbshowpost.php?bbtopic_id=123

Use with care.

(there is no active development)


## Interface

- **PulsePattern()** constructor
- **void init(uint8_t pin, uint16_t\*ar, uint8_t size, luint8_t evel, uint8_t prescaler)** initializer of the Timer1
   - pin that outputs the pattern
   - array of durations
   - size (or part) of the array to be used
   - starting level HIGH/LOW
   - prescaler, one of the 5 defines from .h file (table below)
- **void setFactor(float perc)** percentage = factor to correct timing (relative).
- **float getFactor()** get the internal used factor. Due to rounding it can be slightly different.
- **void stop()** stop the pattern generator
- **void start()** start the pattern generator
- **void cont()** continue the pattern generator from the last stopped place (approx).
- **bool isRunning()** status indicator
- **void worker()** must be public otherwise the ISR cannot call it.

There is some bad understood __vector_11() error when worker() is private.


## Prescaler constants

| Value | Prescaler      | Timer1     | Notes       |
|:-----:|:---------------|:-----------|:-----------:|
|  0    | NO_CLOCK       | timer off  | 
|  1    | PRESCALE_1     | clk / 1    | 
|  2    | PRESCALE_8     | clk / 8    | 
|  3    | PRESCALE_64    | clk / 64   | 
|  4    | PRESCALE_256   | clk / 250  | 
|  5    | PRESCALE_1024  | clk / 1024 | about 1 ms / pulse
|  6    | EXT_T1_FALLING | T1 = pin 5 | not tested
|  7    | EXT_T2_RISING  |            | not tested


# Operation

See examples.


## Future

- ESP32 variant of this class (base class -> AVR -> ESP class)
- pulse recorder class to record / generate patterns

if time permits ...
