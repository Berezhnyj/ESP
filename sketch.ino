/**************************************************************/
/*------------------------------------------------------------*/
/*----------------------------HASP----------------------------*/
/*------------------------------------------------------------*/
/**************************************************************/
// Include Libraries
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME280.h"
/*-----------------Підключення до Wifi мережі-----------------*/

/* Object initialization */
IPAddress   ip_addr;
IPAddress   subnet;
IPAddress   gateway;
/* Object initialization */
const char* path         = "/light.json";
const char* ssid         = "***";
const char* password     = "***";
const char* server_name  = "***";
const char* deviceid     = "2";
const char* json_light   = "NULL";
unsigned int server_port = 80;
unsigned long timer_start;
unsigned long timer_stop;
/* Global variables and defines */
#define DELAY   100000  // Setup delay
#define DHTPIN  2       // DHT22 connect to pin 0
#define LED     D0      // Led in NodeMCU at pin GPIO16 (D0).
#define SEC     1000
#define SEALEVELPRESSURE_HPA (1013.25)
/* jsonBuffer initialization */
StaticJsonDocument<256> jsonBuffer;
/* BME280 initialization */
Adafruit_BME280 bme;
/* WiFiClient initialization */
WiFiClient client;

/*------------------------------------------------------------*/
/*----------------------------SETUP---------------------------*/
/*------------------------------------------------------------*/
void setup()
{
  int count = 0;
  /* Init Serial port at 115200 bps*/
  Serial.begin(115200);
  while (!Serial) continue; // wait for serial port to connect. Needed for native USB
  if (!bme.begin(0x76)) {
    while(1);
  } else {
  }
  /* Connect to Wi-Fi */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(SEC);
    Serial.print("*");
    count++;
    if (count >= 10){
    }
  }

}
/*------------------------------------------------------------*/
/*----------------------------FUNC----------------------------*/
/*------------------------------------------------------------*/
/* print your gateway macAddress */
void set_timer_start()
{
  timer_start = 0;
  timer_stop = 0;
  timer_start = millis();
}
/* print your gateway macAddress */
void set_timer_stop(char* ch)
{
  timer_stop = millis();
  float time_ = ((float)timer_stop - (float)timer_start)/1000;
  if(time_ >= 60){
  } else {
  }
}
/*------------------------------------------------------------*/
/*----------------------------LOOP----------------------------*/
/*------------------------------------------------------------*/
void loop() 
{
  /* Config client with no delay to fast connection */
  client.setNoDelay(1);
  /* Get data from sensors */
  float raw_light_analog  =  analogRead(A0);
  float bme_humidity    = bme.readHumidity();   // Читання температури і вологості
  float bme_temperature = bme.readTemperature();// займає близько 250 мілісекунд!
  float bme_pressure    = bme.readPressure() / 100.0F;// займає близько 250 мілісекунд!
  float bme_altitude    = bme.readAltitude(SEALEVELPRESSURE_HPA);// займає близько 250 мілісекунд!
  float wifi_get_rssi   = WiFi.RSSI();
  char* rellay          = "OFF";

  /* Connect to server */
  if (client.connect(server_name, server_port))
  {
    set_timer_stop("\n\t[DONE] Client is connect time took :");
    set_timer_start();
    client.print(String("GET ") + path + " HTTP/1.1\r\n" +
                  "Host: " + server_name + "\r\n" + 
                  "Connection: keep-alive\r\n\r\n");
    delay(100); // wait for server to respond
    String section = "header";
    set_timer_stop("[DONE] GET path time took :");
    
    while(client.available())
    {
      
      String line = client.readStringUntil('\r');
      // we’ll parse the HTML body here
      if (section == "header") { // headers..
        if (line == "\n") { // skips the empty space at the beginning 
          section="json";
        }
      } else if (section=="json"){  // print the good stuff
        section = "ignore";
        String result = line.substring(1);
        StaticJsonDocument<256> jsonBuffer;
        // ArduinoJson 6
        set_timer_start();
        DeserializationError error = deserializeJson(jsonBuffer, result);
        set_timer_stop("[DONE] GET JSON time took :");
        json_light = jsonBuffer["light"];
        if (error) {
            Serial.print(F("\t[ERROR] deserializeJson() failed with code "));
            Serial.println(error.c_str());
            return;
        }
        // Make the decision to turn off or on the LED
        if ((String)json_light == "off") {
          //digitalWrite(LED, HIGH);
        } else {
          //digitalWrite(LED, LOW);
        }
      }
      
    }
    
    client.print(String("GET /sensor.php?temperature=" + String(bme_temperature) + 
                  "&humidity=" + String(bme_humidity) + 
                  "&pressure=" + String(bme_pressure) + 
                  "&altitude=" + String(bme_altitude) + 
                  "&devnum=" + String(deviceid)+ 
                  "&photo=" + String(raw_light_analog) +
                  "&rellay=" + String(rellay) +
                  "&rssi=" + String(wifi_get_rssi)+
                  " HTTP/1.1\r\n") +
                  "Host: " + server_name + " \r\n" +
                  "Connection: keep-alive\r\n\r\n");
    Serial.println((String)"\t .: Temperature:\t" + bme_temperature + " C");

    client.stop();
  } else {
  }
  wifi_set_sleep_type(LIGHT_SLEEP_T);
  set_timer_start();
  //delay(DELAY); // Delay for 1.66min.
  set_timer_stop("[DONE] Delay time took :");
}
