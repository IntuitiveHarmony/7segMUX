# 7segMUX

Explore the World of Multiplexers with Arduino Uno 🧩

This project delves into the fascinating realm of multiplexers, using a 74HC4052 multiplexer, an Arduino Uno, a 7-segment LED display, a push button, and a potentiometer to showcase their potential.

![Demo](demo.gif)

## Introduction

Multiplexers are essential components that use logical operations to route a single input to one of several outputs. They can significantly reduce the number of pins required on an Arduino or any microcontroller. In this project, we focus on their application with LEDs, as multiplexers allow us to cycle through different outputs rapidly, creating the illusion of multiple LEDs being lit simultaneously.

## Code

To experience this concept firsthand, we've developed a sketch where pressing a button increments a number displayed on the seven-segment LED. The potentiometer controls the rate at which the multiplexer cycles through each LED segment.

Here's an excerpt of the code that illustrates how we display the number 4:

```cpp
// Use multiplexer logic to illuminate each segment individually
void segB() {
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
  digitalWrite(S2, LOW);
}

// (Additional segment functions here...)

// Cycle through each segment; the refresh rate is controlled by the potentiometer 
void display4() {
  segB();
  delay(refreshRate);
  segC();
  delay(refreshRate);
  segF();
  delay(refreshRate);
  segG();
  delay(refreshRate);
}
```

## Wiring Diagram

In our setup, we employed three striped wires to manage the logic and power supply for each of the eight LED segments individually.

![Wiring Diagram](muxDiagram.png)