# Smart IoT gateway based on ESP8266/ESP32

This project brings support for the ESP8266 chip to the Arduino environment. It lets you write sketches, using familiar Arduino functions and libraries, and run them directly on ESP8266, with no external microcontroller required.

ESP8266 Arduino core comes with libraries to communicate over WiFi using TCP and UDP, set up HTTP, mDNS, SSDP, and DNS servers, do OTA updates, use a file system in flash memory, and work with SD cards, servos, SPI and I2C peripherals.

**IoT gateway include next features:**
- configured WiFi settings;
- configured request header;
- integrated OTA updates;

**IoT gateway include next protocols:**
- Modbus RTU protocol;
- CAN Bus (test mode);
- TCP/IP;
- I2C;
- UART;

## Installation of Additional Libraries
The firmware was written under the Arduino IDE. You will need the following additional libraries:
- <Wire.h>                https://www.arduinolibraries.info/libraries/one-wire
- <ESP8266HTTPClient.h>   https://www.arduinolibraries.info/libraries/http-client
- <ESP8266WiFi.h>         https://www.arduinolibraries.info/libraries/adafruit-esp8266
- <ESP8266mDNS.h>         https://www.arduinolibraries.info/libraries/esp8266_mdns
- <ESP8266WebServer.h>    https://www.arduinolibraries.info/libraries/rich-http-server
- <WiFiUdp.h>             https://www.arduinolibraries.info/libraries/dst-rtc
- <ArduinoOTA.h>          https://www.arduinolibraries.info/libraries/arduino-ota
- <ArduinoJson.h>         https://www.arduinolibraries.info/libraries/arduino-json
- <Adafruit_Sensor.h>     https://www.arduinolibraries.info/libraries/dht-sensor-library
- <ModbusMaster232.h>     https://www.arduinolibraries.info/libraries/modbus-master
- "Adafruit_BME280.h"     https://www.arduinolibraries.info/libraries/adafruit-bme280-library

## Building with make
makeEspArduino is a generic makefile for any ESP8266 Arduino project. Using make instead of the Arduino IDE (https://www.arduino.cc/) makes it easier to do automated and production builds.
