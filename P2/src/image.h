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
	std::vector<unsigned char> pixelData;
public:
	bool read(string filename);
	bool write(string filename);

	// accessors ----------------------
	short getWidth() const;
	short getHeight() const;
	unsigned char getChannel(int pixelIndex, int channel) const;
	vector<unsigned char> getChannelDataVector() const;
	Header getHeader() const;

	// mutator ------------------------
	void setChannel(int pixelIndex, int channel, unsigned char newPixelValue);
	void setChannelDataVector(const vector<unsigned char>& newChannelDataVector);
	void setHeader(const Header& newHeader);

};

// OUTSIDE FUNCTION  ------------------

// edit functions ---------------------
Image multiply(const Image& img1, const Image& img2);
Image subtract(const Image& img1, const Image& img2);
Image screen(const Image& img1, const Image& img2);
Image overlay(const Image& img1, const Image& img2);
Image addGreen(const Image& ing);
Image scaleBlueRed(const Image& img);
Image greyScaleIntensity(const Image& img, int channel);

// test functions ---------------------
bool compareImages(Image& img1, Image& img2);
bool runSingleTest(string img1, string img2, string testNum);
void runAllTests();