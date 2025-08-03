# Light Meter Project

A light measurement project using an Arduino, an LDR sensor, and LEDs to indicate ambient light levels.

## 📋 Description

This project uses a Light Dependent Resistor (LDR) to measure ambient light intensity. Based on the sensor readings, different LEDs light up to indicate the detected brightness level.

## ⚙️ Components Used

- 1x Arduino Uno (or compatible)
- 1x LDR sensor
- 4x LEDs (various colors)
- 4x Resistors for LEDs (220Ω or 330Ω)
- 1x Resistor for the LDR (10kΩ recommended)
- Jumper wires and a breadboard

## 🔌 Schematic

- The LDR is connected in a voltage divider with the 10kΩ resistor, which is then connected to one of the Arduino’s analog inputs.
- Each LED is connected to a digital pin on the Arduino with a current-limiting resistor.

![Simulation](circuit_images/image_simulador.png)  
![Physical Circuit](circuit_images/Circuito_real.jpg)

## 💻 How It Works

- The Arduino reads the analog value from the LDR.
- Depending on the reading, a different number of LEDs light up to indicate whether the environment is bright, medium, dark, or very dark.
- Reference values can be adjusted in the code as needed.

## 🚀 How to Use

1. Assemble the circuit according to the schematic.
2. Open the file `sketch_light_meter/sketch_light_meter.ino` in the Arduino IDE.
3. Select the correct board and port.
4. Upload the code to the Arduino.
5. Watch the LEDs indicate the ambient light level.

## 📝 Code

The code is available in the [`sketch_light_meter`](./sketch_light_meter/sketch_light_meter.ino) folder.

## 📄 License

This project is licensed under the MIT License.

---

*Developed by Felipe Grolla*
