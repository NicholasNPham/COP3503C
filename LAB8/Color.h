#pragma once
#include <string>
using std::string;

class Color
{
	string _name;
	string _hexValue;
	unsigned char _r;
	unsigned char _g;
	unsigned char _b;
public:
	static string ByteToHex(unsigned char channel);
	
	Color();
	Color(string name, int value);

	string GetName() const;
	string GetHexValue() const;
	unsigned char GetR() const;
	unsigned char GetG() const;
	unsigned char GetB() const;
};