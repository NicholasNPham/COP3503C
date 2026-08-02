#include <iostream>
#include "Color.h"
using namespace std;

string Color::ByteToHex(unsigned char channel)
{
	string hex = "";

	unsigned char high = channel / 16;
	unsigned char low = channel % 16;

	if (high < 10)
	{
		hex = (char)('0' + high);
	}
	else
	{
		hex = (char)('A' + (high - 10));
	}

	if (low < 10)
	{
		hex += (char)('0' + low);
	}
	else
	{
		hex += (char)('A' + (low - 10));
	}

	return hex;
}

Color::Color()
{
	_name = "";
	_hexValue = "000000";
	_r = 0;
	_g = 0;
	_b = 0;
}

Color::Color(string name, int value)
{
	_name = name;

	unsigned char rValue = (value / 256 / 256) % 256;
	unsigned char gValue = (value / 256) % 256;
	unsigned char bValue = value % 256;

	_hexValue = "0x" + ByteToHex(rValue) + ByteToHex(gValue) + ByteToHex(bValue);
	_r = rValue;
	_g = gValue;
	_b = bValue;

}

string Color::GetName() const {
	return _name;
}

string Color::GetHexValue() const {
	return	_hexValue;
}

unsigned char Color::GetR() const {
	return _r;
}

unsigned char Color::GetG() const {
	return _g;
}

unsigned char Color::GetB() const {
	return _b;
}