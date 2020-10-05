// Include Libraries
#include <Wire.h>
#include <ESP8266HTTPClient.h>

uint32_t    timer_start;
uint32_t    timer_stop;

void set_timer_start();
float set_timer_stop();

void print_cli_start_message() {
    Serial.println("//--------------------------------------------------------------//");
    Serial.println("//--------------------------------------------------------------//");
    Serial.println("//--------------------- SMART ARMS SYSTEM ----------------------//");
    Serial.println("//--------------------------------------------------------------//");
    Serial.println("//--------------------------- START ----------------------------//");
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

void debugPrintMessage(char *code, char *message) {
    Serial.println((String)"");
}
/*
static httpd_handle_t start_webserver(void)
{
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    // Start the httpd server
    ESP_LOGI(TAG, "Starting server on port: '%d'", config.server_port);
    if (httpd_start(&server, &config) == ESP_OK) {
        // Set URI handlers
        ESP_LOGI(TAG, "Registering URI handlers");
        httpd_register_uri_handler(server, &hello);
        //httpd_register_uri_handler(server, &echo);
        //httpd_register_uri_handler(server, &ctrl);
        httpd_register_err_handler(server, HTTPD_404_NOT_FOUND, http_404_error_handler);
        return server;
    }

    ESP_LOGI(TAG, "Error starting server!");
    return NULL;
}*/