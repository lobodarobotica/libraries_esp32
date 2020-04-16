#include "ConvertClass.h"

const char *ConvertClass::int_to_char(int i)
{
	String str = String(i) + "\0";
	const char *cstr2 = str.c_str();
	return cstr2;
}
