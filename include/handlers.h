
void print_cli_start_message() {
  if(CLI_DEBUG_LOGS) {
    Serial.println("//--------------------------------------------------------------//");
    Serial.println("//--------------------------------------------------------------//");
    Serial.println("//--------------------- SMART ARMS SYSTEM ----------------------//");
    Serial.println("//--------------------------------------------------------------//");
    Serial.println("//--------------------------- START ----------------------------//");
  }
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