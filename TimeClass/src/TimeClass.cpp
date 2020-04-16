#include "TimeClass.h"
#include "time.h"



void TimeClass::begin()
{
	configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

char *TimeClass::print_local_time()
{
	struct tm timeinfo;
	if (!getLocalTime(&timeinfo))
	{
		Serial.println("Falha ao obter a hora");
	}

	char timeStringBuff[50];
	strftime(timeStringBuff, sizeof(timeStringBuff), "%A, %B %d %Y %H:%M:%S", &timeinfo);
	Serial.println(timeStringBuff);
	return timeStringBuff;
}
