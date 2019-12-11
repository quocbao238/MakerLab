/*
   Tool Board :  ESP32_Wrover_Module
   Partition Scheme : Huge APP(3MB_NO_OTA)
   
   Creat WiFi AcessPoint
    ID : Gen2
    PW : makershopvn123

*/


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "MakerShop_Gen2";
const char* pass = "123456789";
ESP8266WebServer server(80);

String command;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, pass);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Starting WEB-server
  server.on ( "/", HTTP_handleRoot );
  server.onNotFound ( HTTP_handleRoot );
  server.begin();
  Serial.println("Begin Send Data");

}

void loop() {
  server.handleClient();
  command = server.arg("Makershop");
  //  if (command != "" && command != lastcommand)
  //  {
  //    Serial.println(command);
  //    lastcommand = command;
  //    command = "";
  //  }

  if (command != "")
  {
    Serial.println(command);
    command = "";
  }

}
//
void HTTP_handleRoot(void) {

  if ( server.hasArg("Makershop") ) {
    Serial.println(server.arg("Makershop"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}