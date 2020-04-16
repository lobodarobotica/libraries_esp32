/*********************************************************************************************************
**********************************************************************************************************			
								Library: LogClass												**
								Organizacao: Engetech													**
								Autor: Eng. Mateus Domingues Dias										**
								Email: mateusxdias@gmail.com											**
								Release: 10																**
								Data do release 14/02/2019												**
**********************************************************************************************************/
/*********************************************************************************************************/

#ifndef _TimeClass_h
#define _TimeClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class TimeClass
{
protected:
	

public:
	void begin();
	char* print_local_time();
};
#endif
