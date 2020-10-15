/************************************************************************************/
/*----------------------------------------------------------------------------------*/
/*---------------------------------------HASP---------------------------------------*/
/*----------------------------------------------------------------------------------*/
/************************************************************************************/
/* Global variables and defines */
#define I2C_MODE        FALCE // Define flag to enable I2C_MODE
#define COAP_MODE       FALSE // Define flag to enable COAP_MODE
#define MODBUS232_MODE  FALSE // Define flag to enable MODBUS232_MODE
#define OTAUPDATE_MODE  FALSE // Define flag to enable OTAUPDATE_MODE

// Include Libraries
#include <Wire.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
//#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include "handlers.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#if (OTAUPDATE_MODE)
  #include <ArduinoOTA.h>
#endif
#if (MODBUS232_MODE)
  #include <ModbusTCPSlave.h>
#endif
#if (CANBUS_MODE)
  #include <mcp_can.h>
  #include <SPI.h>
#endif
#if (COAP_MODE)
  #include <WiFiUdp.h>
  #include <coap-simple.h>
#endif



/*----------------------------Підключення до Wifi мережі---------------------------*/
/* Wi-Fi settings */
#define STASSID "OzzyHome_2G"
#define STAPSK  "19951995"
/* Pin board settings */
#define PIN_DHT 2       // DHT22 connect to pin 2
#define PIN_LED 9       // LED connect to pin 9
#define LED     D0      // Led in NodeMCU at pin GPIO16 (D0).
/* Real Time Clock settings */
#define RTC_DELAY   100000  // Setup delay
#define RTC_SEC     1000    // One Sec define
#define RTC_mSEC    100     // One mSec define
#define SEALEVELPRESSURE_HPA (1013.25)
/* Object initialization */
IPAddress   ESP_ip_addr;
IPAddress   ESP_subnet_addr;
IPAddress   ESP_gateway_addr;
IPAddress   dev_ip(0,0,0,0);
/* Object initialization */
const char* ssid         = STASSID;
const char* password     = STAPSK;
const char* server_name  = "smartarms.in.ua";
const char* deviceid     = "2";
const char* json_light   = "NULL";
const char* path         = "/light.json";
char incomingPacket[255];  // buffer for incoming packets
char replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back
uint32_t response = 0;
const char* type_of_OTA;
unsigned int server_port = 80;
unsigned int localUdpPort = 4210;  // local port to listen on
unsigned long timer;
unsigned long checkRSSIMillis;
bool WiFiConnected = false;
//WIFI Settings
byte mac[]            = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };
byte modbus_ip[]      = { 192, 168, 1, 126};
byte modbus_gateway[] = { 192, 168, 1, 1 };
byte modbus_subnet[]  = { 255, 255, 255, 0 };

DynamicJsonDocument jsonBufferGet(2048);  /* DynamicJsonDocument initialization */
Adafruit_BME280 bme;                      /* BME280 initialization */
WiFiClient client;                        /* WiFiClient initialization */
HTTPClient http;                          /* HTTPClient initialization */
ESP8266WebServer server(server_port);     /* ESP8266WebServer initialization */

#if (COAP_MODE) 
  ModbusTCPSlave ModbusSlave;               /* ModbusTCPSlave initialization */
#endif

#if (OTAUPDATE_MODE)
  WiFiUDP Udp;                              /* WiFiUDP initialization */
#endif

  #if (CANBUS_MODE)
  long unsigned int rxId;
  unsigned char len = 0;
  unsigned char rxBuf[8];
  
  MCP_CAN CAN0(4);                               // Set CS to pin 4 (D2 on my NodeMCU)
  unsigned char stmp[8] = {0, 1, 2, 3, 4, 5, 6, 7
#endif

#if (COAP_MODE) 
  void callback_response(CoapPacket &packet, IPAddress ip, int port);
  void callback_light(CoapPacket &packet, IPAddress ip, int port);
#endif

void handle_NotFound();
String SendHTML(float bme_temperature,float bme_humidity);
byte checkRSSI();

/*---------------------------------------------------------------------------------*/
/*--------------------------------------SETUP--------------------------------------*/
/*---------------------------------------------------------------------------------*/
void setup() {
  int count = 0;            /* Init Serial port at 115200 bps*/
  Serial.begin(115200);     // Initialize Serial port at 115200 bps

  #if (I2C_MODE)
    Wire.begin();        // join i2c bus (address optional for master)
  #endif

  #if (COAP_MODE)
    Udp.begin(localUdpPort);  // begin coap server/client
    Serial.println("[INFO] Setup Callback Light");
    coap.server(callback_light, "light");
    // client response callback. this endpoint is single callback.
    Serial.println("[INFO] Setup Response Callback");
    coap.response(callback_response);
    coap.start();             // start coap server/client
  #endif

  #if (MODBUS232_MODE)
    Serial.println("[INFO] Modbus RTU Master Online");
      ModbusSlave.begin("Telecom-28778737", "passwordwificasa47893000",
            modbus_ip, modbus_gateway, modbus_subnet);
      delay(1000);
      ModbusSlave.MBInputRegister[0] = 100;
      ModbusSlave.MBInputRegister[1] = 65500;
      ModbusSlave.MBInputRegister[2] = 300;
      ModbusSlave.MBInputRegister[3] = 400;
      ModbusSlave.MBInputRegister[4] = 500;
      ModbusSlave.MBHoldingRegister[0] = 1;
      ModbusSlave.MBHoldingRegister[1] = 2;
      ModbusSlave.MBHoldingRegister[2] = 3;
      ModbusSlave.MBHoldingRegister[3] = 4;
      ModbusSlave.MBHoldingRegister[4] = 5;
  #endif
  /*
  *   CNF1 = 0x40
  *   CNF2 = 0xF1
  *   CNF3 = 0x85
  */
  #if (CANBUS_MODE)
    CAN0.begin(CAN_250KBPS);                       // init can bus : baudrate = 250k 
    pinMode(2, INPUT);                            // Setting pin 2 for /INT input (D4 on NodeMCU)
    Serial.println("MCP2515 Library Receive Example...");
    Serial.print("CANSTAT: ");Serial.println(CAN0.mcp2515_readRegister(MCP_CANSTAT),BIN);
    CAN0.mcp2515_modifyRegister(MCP_CANCTRL,MODE_MASK,MODE_LOOPBACK); // MODE_NORMAL MODE_LOOPBACK
    Serial.print("CANSTAT: ");Serial.println(CAN0.mcp2515_readRegister(MCP_CANSTAT),BIN);  
  #endif
  
  
  while (!Serial) continue; // wait for serial port to connect. Needed for native USB
  print_cli_start_message();
  
  if (!bme.begin(0x76)) {
    Serial.println("[ERROR] SENSOR BME ERROR! Please check connection!");
    while(1);
  } else {
    Serial.println("[INFO] BME SENSOR is initialise!");
  }
  
  Serial.println("//------------------------ WI-FI START -------------------------//");
  /* Scan Wi-Fi Networks */
  byte numSsid = WiFi.scanNetworks();
  Serial.println((String)"[INFO] Scan Networks\n\tAvailable WiFi discovered: [" + numSsid + "] network(s) found");
  for (int i = 0; i < numSsid; i++)
  {
    Serial.println((String)"\t[" + (i+1) + "] " + WiFi.SSID(i+1));
  }
  Serial.println("//------------------------- CONNECTING -------------------------//");
  /* Connect to Wi-Fi */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("[INFO] Please be patient. Connecting : ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(RTC_SEC);
    Serial.print("*");
    if ((count%10)==true) Serial.print("\n[INFO] Please be patient. Connecting : ");
    count++;
  }

  #if (OTAUPDATE_MODE)
    ArduinoOTA.setPort(8266);
    ArduinoOTA.setHostname("NODE ESP8266");
    ArduinoOTA.onStart([]() {
      if (ArduinoOTA.getCommand() == U_FLASH) type_of_OTA = "sketch";
      else type_of_OTA = "filesystem";
      Serial.println((String)"[START] ESP8266 OTA updating :" + type_of_OTA);
    });
    ArduinoOTA.onEnd([]() {
      Serial.println("[ END ] ESP8266 OTA");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
      Serial.printf("[ERROR] OTA : [%u] : ", error);
      if (error == OTA_AUTH_ERROR)          Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR)    Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR)  Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR)  Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR)      Serial.println("End Failed");
    });
    ArduinoOTA.begin();
  #endif
  /* print your gateway localIP */
  ESP_ip_addr = WiFi.localIP();
  ESP_gateway_addr = WiFi.gatewayIP();
  ESP_subnet_addr = WiFi.subnetMask();
  /* print your Sensor ID and server */
  Serial.println((String)"\n┌──[DONE] Connected to : [" + WiFi.status() + "] " + ssid);
  Serial.println((String)"├──[INFO] WiFi connected sucsses! Time to connection: " + count + "s");
  Serial.println((String)"└──┬──x-ESP8266-Sensor ID\t:\t"       + deviceid);
  Serial.println((String)"   ├──x-ESP8266-Server\t:\t"       + server_name + ":" + server_port);
  Serial.println((String)"   ├──x-ESP8266-STA-LOCAL-IP\t:\t"    + ESP_ip_addr.toString());
  Serial.println((String)"   ├──x-ESP8266-STA-GATEWAY\t:\t"     + ESP_gateway_addr.toString());
  Serial.println((String)"   ├──x-ESP8266-STA-NETMASK\t:\t"     + ESP_subnet_addr.toString());
  Serial.println((String)"   ├──x-ESP8266-STA-MAC\t\t:\t"       + WiFi.macAddress());
  Serial.println((String)"   ├──x-ESP8266-AP-MAC\t\t:\t"        + WiFi.softAPmacAddress());
  Serial.println((String)"   ├──x-ESP8266-sketch-md5\t\t:\t"    + (String)ESP.getSketchMD5());
  Serial.println((String)"   ├──x-ESP8266-sdk-version\t:\t"     + (String)ESP.getSdkVersion());
  Serial.println((String)"   ├──x-ESP8266-Core-Version\t:\t"    + (String)ESP.getCoreVersion() + "-Core-Version");
  Serial.println((String)"   ├──x-ESP8266-free-space\t\t:\t"    + (String)ESP.getFreeSketchSpace() + "/" + (String)ESP.getSketchSize());
  Serial.println((String)"   ├──x-ESP8266-fragmentation\t:\t"   + (String)ESP.getHeapFragmentation() + "%");
  Serial.println((String)"   ├──x-ESP8266-Max-Free-Block\t:\t"  + (String)ESP.getMaxFreeBlockSize() + "RAM");
  Serial.println((String)"   ├──x-ESP8266-Cpu-Freq\t\t:\t"      + (String)ESP.getCpuFreqMHz() + "MHz");
  Serial.println((String)"   └──x-ESP8266-reset-reason\t:\t"    + (String)ESP.getResetReason());

  //server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);
  server.begin();
}

/*---------------------------------------------------------------------------------*/
/*--------------------------------------LOOP---------------------------------------*/
/*---------------------------------------------------------------------------------*/
void loop() 
{
  #if (COAP_MODE)
    Serial.print("[INFO] Send Request: ");
    int msgid = coap.get(IPAddress(0, 0, 0, 0), 5683, "time");
    Serial.println(msgid);
    delay(1000);
    coap.loop();
  #endif

  #if (I2C_MODE)
    Wire.requestFrom(8, 6);    // request 6 bytes from slave device #8
    while (Wire.available()) { // slave may send less than requested
      char message_from_I2C = Wire.read(); // receive a byte as character
      Serial.println((String)"[INFO] " + message_from_I2C);         // print the character
    }
    delay(500);
  #endif

  #if (OTAUPDATE_MODE)
    ArduinoOTA.handle();
  #endif

  #if (MODBUS232_MODE)
    ModbusSlave.Run();
    delay(10);

    if (millis() - timer >= 1000) {
      timer = millis();
      ModbusSlave.MBInputRegister[1]++;
    }

    if (millis() - checkRSSIMillis >= 10000) {
      checkRSSIMillis = millis();
      ModbusSlave.MBInputRegister[0] = checkRSSI();
    }
  #endif

  #if (CANBUS_MODE)
    if(!digitalRead(2))                         // If pin 2 is low, read receive buffer
    {
      CAN0.readMsgBuf(&len, rxBuf);              // Read data: len = data length, buf = data byte(s)
      rxId = CAN0.getCanId();                    // Get message ID
      Serial.print("ID: ");
      Serial.print(rxId, HEX);
      Serial.print("  Data: ");
      for(int i = 0; i<len; i++)                // Print each byte of the data
      {
        if(rxBuf[i] < 0x10)                     // If data byte is less than 0x10, add a leading zero
        {
          Serial.print("0");
        }
        Serial.print(rxBuf[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
    }
    // send data:  id = 0x00, standrad flame, data len = 8, stmp: data buf
    if(Serial.available()){
    stmp[0] = Serial.read();
    if(stmp[0] == 'l'){
    CAN0.mcp2515_modifyRegister(MCP_CANCTRL,MODE_MASK,MODE_LOOPBACK); // MODE_NORMAL MODE_LOOPBACK
    }
    if(stmp[0] == 'n'){
    CAN0.mcp2515_modifyRegister(MCP_CANCTRL,MODE_MASK,MODE_NORMAL); // MODE_NORMAL MODE_LOOPBACK
    }

    }
    CAN0.sendMsgBuf(0x00, 0, 8, stmp);
    //Serial.print("CANSTAT: ");Serial.println(CAN0.mcp2515_readRegister(MCP_CANSTAT),BIN);  
    delay(100);                       // send data per 100ms
  #endif

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
  char *rellay          = "ON";
  /* HTTPClient Send request GET */
  set_timer_start();
  http.useHTTP10(true);
  http.begin((String)"http://" + server_name + "/" + path);
  int httpGetResponseCode = http.GET();
  String payload = http.getString();    //Get the response payload from server
  delay(1000); // Delay for 1.66min.
  DeserializationError error = deserializeJson(jsonBufferGet, payload);
  if (error) Serial.println((String)"[ERROR] deserializeJson() failed with code :\"" + error.c_str() + "\";");
  /* HTTPClient Read values */
  json_light = jsonBufferGet["user_setting"]["light"];
  /* Make the decision to turn off or on the LED */
  if ((String)json_light == "off") digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);
  /* HTTPClient Disconnect */
  Serial.println((String)"[OK] ResponseCode : [" + httpGetResponseCode + "] Response : \n" + payload + "[INFO] ResponseTook: " + set_timer_stop() + "s");   //Print return code
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
  http.begin((String)"http://" + (String)server_name + "/sensor.php");  //Specify destination for HTTP request
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
  
  int httpResponseCode = http.POST(postData);   //Send the actual POST request
  
  if(httpResponseCode>0)
  {
    String response = http.getString(); //Get the response to the request
    Serial.println((String)"┌──[REQUEST]───[POST]:");
    Serial.println((String)"└──┬──: Temperature:\t"       + bme_temperature + " C");
    Serial.println((String)"   ├──: Humidity:\t\t"        + bme_humidity + " %");
    Serial.println((String)"   ├──: Photo:\t\t"           + light_analog + " LUM");
    Serial.println((String)"   ├──: Pressure:\t\t"        + bme_pressure + " hPa");
    Serial.println((String)"   ├──: Altitude:\t\t"        + bme_altitude + "m");
    Serial.println((String)"   ├──: Signal strength: \t"  + wifi_get_rssi + "dBm");
    Serial.println((String)"   └──: Rellay:\t\t\""        + json_light + "\"");
    Serial.println("//--------------------------------------------------------------//");
    Serial.println((String)"[INFO] ResponseCode : [" + httpResponseCode + "] Response : " + response + "[INFO] ResponseTook: " + set_timer_stop() + "s");   //Print return code
  } else {
    Serial.println((String)"[ERROR] Error on sending POST: " + httpResponseCode);
  }
  http.end();  //Free resources

  wifi_set_sleep_type(LIGHT_SLEEP_T);
  Serial.println("┌──[DONE] Light sleep enabled!");
  Serial.println("└────────> Please whate for wake up!");
  set_timer_start();
  delay(RTC_DELAY); // Delay for 1.66min.
  Serial.println((String)"[DONE] Wake Up ... Delay time took :" + set_timer_stop());
}
/*------------------------------------------------------------*/
/*----------------------------FUNC----------------------------*/
/*------------------------------------------------------------*/
byte checkRSSI() {
  byte quality;
  long rssi = WiFi.RSSI();
  if (rssi <= -100)
    quality = 0;
  else if (rssi >= -50)
    quality = 100;
  else
    rssi = rssi + 100;
  quality = byte(rssi * 2);

  return quality;
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not founds!");
}

String SendHTML(float bme_temperature,float bme_humidity){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>ESP8266 Weather Report</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>ESP8266 NodeMCU Weather Report</h1>\n";
  
  ptr +="<p>Temperature: ";
  ptr +=(String)bme_temperature;
  ptr +="°C</p>";
  ptr +="<p>Humidity: ";
  ptr +=(String)bme_humidity;
  ptr +="%</p>";
  
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}



#if (COAP_MODE)
  bool LEDSTATE;

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
      digitalWrite(PIN_LED, HIGH) ; 
      coap.sendResponse(ip, port, packet.messageid, "1");
    } else { 
      digitalWrite(PIN_LED, LOW) ; 
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
#endif