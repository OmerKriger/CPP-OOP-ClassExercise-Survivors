#include "Bandana.h"
#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

Bandana::Bandana(const char* color, int len) 
{
	setColor(color);
	setLen(len);
}
bool Bandana::setColor(const char* color)
{
	if (strcmp("", color) == 0)
		return false;
	strcpy(this->color, color);
	return true;
}
bool Bandana::setLen(int len) 
{
	if (len < 0)
		return false;
	this->length = len;
	return true;
}

