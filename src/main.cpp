/************************************************************************************/
/*----------------------------------------------------------------------------------*/
/*---------------------------------------HASP---------------------------------------*/
/*----------------------------------------------------------------------------------*/
/************************************************************************************/
/* Include Libraries */
#include <Wire.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ArduinoJson.h>
#include "Adafruit_Sensor.h"
#include <ModbusMaster232.h>
#include "Adafruit_BME280.h"
#include <coap-simple.h>
#include "handlers.h"
/*----------------------------Підключення до Wifi мережі---------------------------*/
/* Global variables and defines */
#define COAPSERVER	true
#define OTAUPDATE	  true
#ifndef MODBUS232
  #define MODBUS232 true  // Define flag to enable ModeBus
  #define address   1     // Define one address for reading
  #define bitQty    1     // Define the number of bits to read
  #define SLAVE_ID  1
  #define Master_ID 1
#endif
#define CLI_DEBUG_LOGS true
#define STASSID "*******"
#define STAPSK  "*******"
#define DEVICE_SECRET_KEY  = "your-device_secret_key";
#define DEVICE_DELAY  100000  // Setup delay
#define DHTPIN  2       // DHT22 connect to pin 0
#define LED     D0      // Led in NodeMCU at pin GPIO16 (D0).
#define SEC     1000    // One Sec define
#define mSEC    100    // One mSec define
#define SEALEVELPRESSURE_HPA (1013.25)
/* Object initialization */
IPAddress   ESP_ip_addr;
IPAddress   ESP_subnet_addr;
IPAddress   ESP_gateway_addr;
IPAddress 	coap_dev_ip(10,10,10,10);
byte coap_mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };
/* Object initialization */
const char* ssid         = STASSID;
const char* password     = STAPSK;
const char* server_name  = "smartarms.in.ua";
const char* deviceid     = "2";
const char* json_light   = "NULL";
const char* type_of_OTA;
unsigned int server_port = 80;
uint32_t    response     = 0;
uint32_t    lastSentTime = 0UL;
uint32_t    timer_start;
uint32_t    timer_stop;
String      path               = "/light.json";

// LED STATE
bool LEDSTATE;

WiFiClient            client;                 /* WiFiClient initialization */
HTTPClient            http;                   /* HTTPClient initialization */
ESP8266WebServer      server(server_port);             /* ESP8266WebServer initialization */
ModbusMaster232       ModbusNode(Master_ID);  /* Instantiate ModbusMaster object as slave ID 1 */
DynamicJsonDocument   jsonBufferGet(2048);    /* DynamicJsonDocument initialization */
Adafruit_BME280       bme;                    /* BME280 initialization */
WiFiUDP               udp;                    /* WiFiUDP */
Coap                  coap(udp);              /* Instance for coapclient */

float set_timer_stop();
void set_timer_start();
void print_cli_start_message();
void set_http_header();
void callback_response(CoapPacket &packet, IPAddress ip, int port);		// CoAP client response callback
void callback_light(CoapPacket &packet, IPAddress ip, int port);		// CoAP server endpoint url callback


/*---------------------------------------------------------------------------------*/
/*--------------------------------Power on setup-----------------------------------*/
/*---------------------------------------------------------------------------------*/
void setup() {
  Serial.begin(115200UL);     // Initialize Serial port at 115200 bps

  if (COAPSERVER == true) {
    Serial.println("Setup Callback Light");
    coap.server(callback_light, "light");
    // client response callback.
    // this endpoint is single callback.
    Serial.println("Setup Response Callback");
    coap.response(callback_response);
    // start coap server/client
    coap.start();
  }
  
  if (MODBUS232 == true) {
    pinMode(7, OUTPUT);
    ModbusNode.begin(115200UL);  // Initialize Modbus communication baud rate
    Serial.println("Modbus RTU Master Online");
  }
  while (!Serial) continue; // wait for serial port to connect. Needed for native USB
  print_cli_start_message();

  if (!bme.begin(0x76)) {
    Serial.println("[ERROR] SENSOR BME ERROR! Please check connection!");
    while(true);
  } else {
    Serial.println("\t[DONE] BME SENSOR is initialise!");
  }

  Serial.println("//------------------------ WI-FI START -------------------------//");
  /* Scan Wi-Fi Networks */
  byte numSsid = WiFi.scanNetworks();
  Serial.println((String)"\tScan Networks\n\tAvailable WiFi discovered: [" + numSsid + "] network(s) found");

  for (int i = 0; i < numSsid; i++) {
    Serial.println((String)"\t\t[" + (i+1) + "] " + WiFi.SSID(i+1));
  }
  Serial.println("//------------------------- CONNECTING -------------------------//");
  /* Connect to Wi-Fi */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("\tPlease be patient. Connecting : ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(SEC);
    Serial.print("*");
  }

  /* Check OTA update system */
  /*ArduinoOTA.setPort(8266);
  ArduinoOTA.setPort(8266);
  ArduinoOTA.setHostname("NODE ESP8266");
  
  ArduinoOTA.onStart([]() {
    if (ArduinoOTA.getCommand() == U_FLASH) type_of_OTA = "sketch";
    else type_of_OTA = "filesystem";
    Serial.println((String)"[START] ESP8266 OTA updating :" + type_of_OTA);
  });

  ArduinoOTA.onEnd([]() { Serial.println("[ END ] ESP8266 OTA"); });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) { Serial.printf("Progress: %u%%\r", (progress / (total / 100))); });
  ArduinoOTA.onError([](ota_error_t error) {
	Serial.printf("[ERROR] OTA : [%u] : ", error);  
	if (error == OTA_AUTH_ERROR)          Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR)    Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR)  Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR)  Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR)      Serial.println("End Failed");
  });
  
  ArduinoOTA.begin();

*/
  
  /* print your gateway localIP */
  ESP_ip_addr = WiFi.localIP();
  ESP_gateway_addr = WiFi.gatewayIP();
  ESP_subnet_addr = WiFi.subnetMask();
  /* print your Sensor ID and server */
  Serial.println((String)"\n\t[DONE] Connected to : [" + WiFi.status() + "] " + ssid);
  Serial.println((String)"\t| x-ESP8266-Sensor ID : "       + deviceid);
  Serial.println((String)"\t| x-ESP8266-Server    : "       + server_name + ":" + server_port);
  Serial.println((String)"\t| x-ESP8266-STA-LOCAL-IP:\t"    + ESP_ip_addr.toString());
  Serial.println((String)"\t| x-ESP8266-STA-GATEWAY:\t"     + ESP_gateway_addr.toString());
  Serial.println((String)"\t| x-ESP8266-STA-NETMASK:\t"     + ESP_subnet_addr.toString());
  Serial.println((String)"\t| x-ESP8266-STA-MAC:\t\t"       + WiFi.macAddress());
  Serial.println((String)"\t| x-ESP8266-AP-MAC:\t\t"        + WiFi.softAPmacAddress());
  Serial.println((String)"\t| x-ESP8266-sketch-md5:\t\t"    + (String)ESP.getSketchMD5());
  Serial.println((String)"\t| x-ESP8266-sdk-version:\t"     + (String)ESP.getSdkVersion());
  Serial.println((String)"\t| x-ESP8266-Core-Version:\t"    + (String)ESP.getCoreVersion() + "-Core-Version");
  Serial.println((String)"\t| x-ESP8266-free-space:\t\t"    + (String)ESP.getFreeSketchSpace() + "/" + (String)ESP.getSketchSize());
  Serial.println((String)"\t| x-ESP8266-fragmentation:\t"   + (String)ESP.getHeapFragmentation() + "%");
  Serial.println((String)"\t| x-ESP8266-Max-Free-Block:\t"  + (String)ESP.getMaxFreeBlockSize() + "RAM");
  Serial.println((String)"\t| x-ESP8266-Cpu-Freq:\t\t"      + (String)ESP.getCpuFreqMHz() + "MHz");
  Serial.println((String)"\t| x-ESP8266-reset-reason:\t"    + (String)ESP.getResetReason());
  Serial.println("\n//-------------------------- CONNECTED -------------------------//");

  //server.on("/", handle_OnConnect);
  //server.onNotFound(handle_NotFound);
  //server.begin();
}

/*---------------------------------------------------------------------------------*/
/*--------------------------------------LOOP---------------------------------------*/
/*---------------------------------------------------------------------------------*/
void loop() {
  if (OTAUPDATE == true) ArduinoOTA.handle();

  if (COAPSERVER == true) {
    coap.get(IPAddress(10, 10, 10, 10), 5683, "time");
    delay(1000);
    coap.loop();
  } else {
    
  }
  if (MODBUS232 == true) {
    /*
    pinMode(4, OUTPUT);     // Initialize pin 4 on ESP module
    ModbusNode.begin(19200);    // Initialize Modbus communication baud rate
    response = ModbusNode.readHoldingRegisters(4, 1); // Write Digital Outputs - Holding Register[4]  /->  [5]
    int led = ModbusNode.getResponseBuffer(0);    // get value - captura valor
    digitalWrite(4,led);            // GPIO 04 
    ModbusNode.clearResponseBuffer();     // Clear the response buffer
    delay(mSEC);
    ModbusNode.writeSingleRegister(5, random(1, 999 ));   // Send Random Value  - Holding Register[5]    /->  [6]
    delay(mSEC);
    ModbusNode.writeSingleRegister(6, analogRead(A0));    //Read Analog Input - Holding Register[6]     /->  [7]
    delay(mSEC);
    ModbusNode.clearResponseBuffer();     // Clear the response buffer
    */
  }
  /* Config client with no delay to fast connection */
  client.setNoDelay(1);

  server.handleClient();
  /* Get data from sensors */
  float bme_humidity    = bme.readHumidity();
  float bme_temperature = bme.readTemperature();
  float bme_pressure    = bme.readPressure() / 100.0F;
  float bme_altitude    = bme.readAltitude(SEALEVELPRESSURE_HPA);
  float light_analog    = analogRead(A0);
  float wifi_get_rssi   = WiFi.RSSI();
  String rellay         = "OFF";
  /* HTTPClient Send request GET */
  set_timer_start();
  http.useHTTP10(true);
  http.begin((String)"http://" + server_name + "/" + path);
  int httpGetResponseCode = http.GET();
  String payload = http.getString();    //Get the response payload from server
  delay(1000); // Delay for 1.66min.
  DeserializationError error = deserializeJson(jsonBufferGet, payload);
  
  if (error) {
    Serial.print(F("\t[ERROR] deserializeJson() failed with code "));
    Serial.println(error.c_str());
  }
  /* HTTPClient Read values */
  json_light = jsonBufferGet["user_setting"]["light"];
  /* Make the decision to turn off or on the LED */
  if ((String)json_light == "off") digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);
  /* HTTPClient Disconnect */
  Serial.println((String)"[OK] ResponseCode : [" + httpGetResponseCode + "] Response : \n" + payload + " took: " + set_timer_stop());   //Print return code
  http.useHTTP10(false);
  http.end();
  /* POST DATA to update database */
  String postData = "temperature=" + String(bme_temperature) + 
          "&humidity="   + String(bme_humidity) + 
          "&pressure="   + String(bme_pressure) + 
          "&altitude="   + String(bme_altitude) + 
          "&devnum="     + String(deviceid)+ 
          "&photo="      + String(light_analog) +
          "&rellay="     + String(rellay) +
          "&rssi="       + String(wifi_get_rssi);
  /* HTTPClient Send request POST */
  set_timer_start();
  set_http_header();

  int httpResponseCode = http.POST(postData);   //Send the actual POST request

  if(httpResponseCode>0)
  {
    String response = http.getString(); //Get the response to the request
    Serial.println((String)"\t .: Temperature:\t"       + bme_temperature + " C");
    Serial.println((String)"\t .: Humidity:\t\t"        + bme_humidity + " %");
    Serial.println((String)"\t .: Photo:\t\t"           + light_analog + " LUM");
    Serial.println((String)"\t .: Pressure:\t\t"        + bme_pressure + " hPa");
    Serial.println((String)"\t .: Altitude:\t\t"        + bme_altitude + "m");
    Serial.println((String)"\t .: Signal strength: \t"  + wifi_get_rssi + "dBm");
    Serial.println((String)"\t .: Rellay:\t\t\""        + json_light + "\"");
    Serial.println("//--------------------------------------------------------------//");
    Serial.println((String)"[OK] ResponseCode : [" + httpResponseCode + "] Response : " + response + " took: " + set_timer_stop());   //Print return code
  } else {
    Serial.println((String)"[ERROR] Error on sending POST: " + httpResponseCode);
  }
  http.end();  //Free resources

  wifi_set_sleep_type(LIGHT_SLEEP_T);
  Serial.println("[DONE] Light sleep enabled! Please whate for wake up!");
  set_timer_start();
  delay(DEVICE_DELAY); // Delay for 1.66min.
  Serial.println((String)"[DONE] Wake Up ... Delay time took :" + set_timer_stop());
}
/*------------------------------------------------------------*/
/*----------------------------FUNC----------------------------*/
/*------------------------------------------------------------*/

void set_http_header() {
  http.begin((String)"http://" + server_name + "/sensor.php");  //Specify destination for HTTP request
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.addHeader("Connection","keep-alive");
  http.addHeader("Host", (String)server_name);
  http.addHeader("Pragma", "no-cache");
  http.addHeader("Cache-Control", "no-cache");
  http.addHeader("Upgrade-Insecure-Requests", "1");
  http.addHeader("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36");
  http.addHeader("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");
  http.addHeader("DNT", "1");
  http.addHeader("Referer", (String)server_name);
  http.addHeader("Accept-Encoding", "gzip, deflate, sdch, br");
  http.addHeader("Accept-Language", "en-US,en;q=0.8");
}
/* Start timer */
void set_timer_start() {
  timer_stop = 0;
  timer_start = micros();
}
/* Stop timer */
float set_timer_stop() {
  timer_stop = micros();
  float time_delta = ((float)timer_stop - (float)timer_start) / 1000;
  if(time_delta >= 60){
    return (time_delta/60);
  } else {
    return (time_delta);
  }
}

void handle_OnConnect() {
  /*float bme_humidity    = bme.readHumidity();
  float bme_temperature = bme.readTemperature();
  float bme_pressure    = bme.readPressure() / 100.0F;
  float bme_altitude    = bme.readAltitude(SEALEVELPRESSURE_HPA);
  float light_analog    = analogRead(A0);
  float wifi_get_rssi   = WiFi.RSSI();
  String rellay          = "OFF";*/
  //String s = SendHTML(bme_temperature, bme_humidity);
  //server.send(200, "text/html", s); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

// coap client response callback
// CoAP server endpoint URL
void callback_light(CoapPacket &packet, IPAddress ip, int port) {
  Serial.println("[Light] ON/OFF");
  
  // send response
  char p[packet.payloadlen + 1];
  memcpy(p, packet.payload, packet.payloadlen);
  p[packet.payloadlen] = 0;
  
  String message(p);

  if (message.equals("0"))
    LEDSTATE = false;
  else if(message.equals("1"))
    LEDSTATE = true;
      
  if (LEDSTATE) {
    digitalWrite(DHTPIN, HIGH) ; 
    coap.sendResponse(ip, port, packet.messageid, "1");
  } else { 
    digitalWrite(DHTPIN, LOW) ; 
    coap.sendResponse(ip, port, packet.messageid, "0");
  }
}
// CoAP client response callback
void callback_response(CoapPacket &packet, IPAddress ip, int port) {
  Serial.println("[Coap Response got]");
  
  char p[packet.payloadlen + 1];
  memcpy(p, packet.payload, packet.payloadlen);
  p[packet.payloadlen] = 0;
  
  Serial.println(p);
}
