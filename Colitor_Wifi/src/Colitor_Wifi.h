#ifndef _Colitor_Wifi_h
#define _Colitor_Wifi_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <FS.h>

class Colitor_Wifi
{
private:
	static void handleRoot();
	int connect();

public:
	void setup();
	boolean loop();
	String colitor_ssid();
};
#endif
