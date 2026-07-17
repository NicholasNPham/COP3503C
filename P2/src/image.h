#pragma once
#include <vector>
#include <string>
using std::string;

struct Header
{
	char idLength;
	char colorMapType;
	char imageType;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short imageWidth;
	short imageHeight;
	char pixelDepth;
	char imageDescriptor;

};

class Image
{
	Header header;
	std::vector<unsigned char> pixels;
public:
	bool read(string filename);
	bool write(string filename);

	// accessors ----------------------
	short getWidth();
	short getHeight();
	unsigned char getPixel(int pixelIndex, int channel);

	// mutator ------------------------
	void setPixel(int pixelIndex, int channel, unsigned char newPixelValue);

};