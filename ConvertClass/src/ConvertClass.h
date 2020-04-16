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

#ifndef _ConvertClass_h
#define _ConvertClass_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ConvertClass
{
protected:
	
public:
	void begin();
	const char* int_to_char(int i);

};
#endif
