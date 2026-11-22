# ESP32-Firebase-Sensor-Monitoring
IoT project using ESP32 and Firebase Realtime Database to monitor sensor readings and control an LED remotely.
# ESP32 Firebase Sensor Monitoring

An IoT project based on the **ESP32** microcontroller and **Firebase Realtime Database**, allowing sensor data monitoring and remote LED control through a cloud database.

## Project Overview

This project connects an ESP32 board to a Wi-Fi network and Firebase Realtime Database to enable communication between hardware and the cloud.

The ESP32 continuously reads an analog sensor value, uploads it to Firebase, and retrieves a value from the database to control an LED.

## Features

- **Wi-Fi Connectivity:** Connects the ESP32 to a wireless network.
- **Sensor Monitoring:** Reads analog values from a connected sensor.
- **Cloud Data Storage:** Sends sensor readings to Firebase Realtime Database.
- **Remote LED Control:** Retrieves the LED control value from Firebase and controls the LED.
- **Automatic Updates:** Repeats the monitoring and control process every second.

## Technologies & Tools

- ESP32 Dev Module
- Arduino IDE
- C/C++ (Arduino)
- Firebase Realtime Database
- Firebase ESP32 Client Library
- Wi-Fi

## Hardware Components

- ESP32 development board
- Analog sensor
- LED
- Connecting wires

## Firebase Database Structure

The project uses the following Realtime Database paths:

```json
{
  "capteur": 0,
  "led": 0
}
```

| Path | Description |
|---|---|
| `/capteur` | Stores the analog sensor reading |
| `/led` | Stores the LED control value |

## How It Works

1. The ESP32 initializes the sensor and LED pins.
2. It connects to the configured Wi-Fi network.
3. It authenticates with Firebase.
4. It reads the analog sensor value.
5. It sends the sensor value to `/capteur`.
6. It retrieves the value stored in `/led`.
7. It updates the LED output according to the retrieved value.
8. The process repeats every second.

## Configuration

Before running the project:

1. Install Arduino IDE.
2. Install the required ESP32 board package.
3. Install the Firebase ESP32 Client library.
4. Configure your Wi-Fi credentials.
5. Configure your Firebase API key and Realtime Database URL.
6. Configure your Firebase authentication credentials.
7. Upload the sketch to your ESP32 board.

**Important:** Never publish Wi-Fi passwords, Firebase account passwords, or private credentials in a public repository. Store them in a separate local configuration file excluded from Git.

## Project Status

Developed as an ESP32 and Firebase IoT project.

