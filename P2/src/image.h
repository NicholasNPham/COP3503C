#pragma once
#include <vector>
#include <string>
using std::string;
using std::vector;

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

	bool operator==(const Header& rhs) const {

		if (idLength == rhs.idLength &&
				colorMapType == rhs.colorMapType &&
				imageType == rhs.imageType &&
				colorMapOrigin == rhs.colorMapOrigin &&
				colorMapLength == rhs.colorMapLength &&
				colorMapDepth == rhs.colorMapDepth &&
				xOrigin == rhs.xOrigin &&
				yOrigin == rhs.yOrigin &&
				imageWidth == rhs.imageWidth &&
				imageHeight == rhs.imageHeight &&
				pixelDepth == rhs.pixelDepth &&
				imageDescriptor == rhs.imageDescriptor)
		{ 
			return true;
		}
		else
		{
			return false;
		}

	}

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
	vector<unsigned char> getPixelVector();
	Header getHeader();

	// mutator ------------------------
	void setPixel(int pixelIndex, int channel, unsigned char newPixelValue);

};

bool compareImages(Image& img1, Image& img2);
bool runSingleTest(Image& img1, Image& img2, string testNum);
void runAllTests();