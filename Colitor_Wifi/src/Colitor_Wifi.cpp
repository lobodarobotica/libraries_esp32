#include "Colitor_Wifi.h"

const char *ssid = "........";
const char *pass = "........";

String s = "";
String p = "";

const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 1, 1);
DNSServer dnsServer;
WebServer server(80);

String content = "<!DOCTYPE html>"
                 "<head><meta name=\"viewport\"content=\"width=device-width,initial-scale=1,user-scalable=no\"/>"
                 "<title>Colitor - AP</title>"
                 "<style>"
                 "form{margin-top:20%;}"
                 "body{background-color: rgb(238, 238, 238);text-align:center;font-family:verdana;}"
                 "h1{font-size:40px; color:#062440;}"
                 "input{padding:5px;font-size:25px; width:90%; margin: 10px}"
                 "#buttonok{background-color:#0083FF; border:0;border-radius:0.3rem;color:#fff;width:95%;}</style></head>"
                 "<body><h1>Colitor Wifi</h1><form action='/' method='POST'>"
                 "<input type='text' name='SSID' placeholder='SSID'><br>"
                 "<input type='password' name='PASSWORD' placeholder='password'><br>"
                 "<input id='buttonok' type='submit' name='SUBMIT' value='Submit'></form><br>"
                 "</body></html>";

void Colitor_Wifi::setup()
{
    WiFi.mode(WIFI_AP);
    delay(100);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
    WiFi.softAP("Colitor-AP");
    delay(200);

    server.on("/", handleRoot);
    dnsServer.start(DNS_PORT, "*", apIP);

    server.onNotFound([]() {
        server.send(200, "text/html", content);
    });

    server.begin();
    delay(50);
}
boolean Colitor_Wifi::loop()
{
    while (true)
    {
        server.handleClient();
        dnsServer.processNextRequest();

        if (s != "" && p != "")
        {
            if (connect() != WL_CONNECTED)
            {
                Serial.println("Failed to connect.");
                return false;
            }
            else
            {
                return true;
                break;
            }
        }
    }
}
void Colitor_Wifi::handleRoot()
{
    if (server.hasArg("SSID") && server.hasArg("PASSWORD"))
    {
        s = server.arg("SSID");
        p = server.arg("PASSWORD");
    }

    server.send(200, "text/html", content);
}
int Colitor_Wifi::connect()
{
    ssid = s.c_str();
    pass = p.c_str();

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    Serial.println("");

    long last_time = millis();
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");

        if (millis() - last_time > 10000)
        {
            return WL_CONNECT_FAILED;
        }
    }

    delay(500);
    return WL_CONNECTED;
}
String Colitor_Wifi::colitor_ssid()
{
    return String(ssid);
}
