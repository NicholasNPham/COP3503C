#include <iostream>
#include <fstream>
#include "image.h"
using namespace std;

bool Image::read(string filename)
{
	ifstream file(filename, ios::binary); // OPEN IN BINARY MODE	

	if (!file.is_open())
	{
		cout << "Could not open: " << filename << endl;
		return false;
	}

	file.read(&header.idLength, sizeof(header.idLength));
	file.read(&header.colorMapType, sizeof(header.colorMapType));
	file.read(&header.imageType, sizeof(header.imageType));
	file.read(reinterpret_cast<char*>(&header.colorMapOrigin), sizeof(header.colorMapOrigin));
	file.read(reinterpret_cast<char*>(&header.colorMapLength), sizeof(header.colorMapLength));
	file.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
	file.read(reinterpret_cast<char*>(&header.xOrigin), sizeof(header.xOrigin));
	file.read(reinterpret_cast<char*>(&header.yOrigin), sizeof(header.yOrigin));
	file.read(reinterpret_cast<char*>(&header.imageWidth), sizeof(header.imageWidth));
	file.read(reinterpret_cast<char*>(&header.imageHeight), sizeof(header.imageHeight));
	file.read(&header.pixelDepth, sizeof(header.pixelDepth));
	file.read(&header.imageDescriptor, sizeof(header.imageDescriptor));

	// ALLOCATING ELEMENTS FOR VECTOR
	int pixelCount = header.imageWidth * header.imageHeight * 3;
	pixelData.resize(pixelCount);
	// PASS RAW POINTER TO FILE.READ()
	// Starts with pixel[0] pixel[786431]
	file.read(reinterpret_cast<char*>(pixelData.data()), pixelCount);


	cout << "Read Operation Successful" << endl;
	return true;
}

bool Image::write(string filename)
{
	ofstream file(filename, ios::binary); // OPEN IN BINARY MODE	

	if (!file.is_open())
	{
		cout << "Could not open: " << filename << endl;
		return false;
	}

	file.write(&header.idLength, sizeof(header.idLength));
	file.write(&header.colorMapType, sizeof(header.colorMapType));
	file.write(&header.imageType, sizeof(header.imageType));
	file.write(reinterpret_cast<char*>(&header.colorMapOrigin), sizeof(header.colorMapOrigin));
	file.write(reinterpret_cast<char*>(&header.colorMapLength), sizeof(header.colorMapLength));
	file.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
	file.write(reinterpret_cast<char*>(&header.xOrigin), sizeof(header.xOrigin));
	file.write(reinterpret_cast<char*>(&header.yOrigin), sizeof(header.yOrigin));
	file.write(reinterpret_cast<char*>(&header.imageWidth), sizeof(header.imageWidth));
	file.write(reinterpret_cast<char*>(&header.imageHeight), sizeof(header.imageHeight));
	file.write(&header.pixelDepth, sizeof(header.pixelDepth));
	file.write(&header.imageDescriptor, sizeof(header.imageDescriptor));

	file.write(reinterpret_cast<char*>(pixelData.data()), pixelData.size());

	cout << "Write Operation Successful" << endl;
	return true;
}

// accessors -------------------------------------------
short Image::getWidth() const
{
	return header.imageWidth;
}

short Image::getHeight() const
{
	return header.imageHeight;
}

unsigned char Image::getChannel(int pixelIndex, int channel) const
{

	// first calulates the index
	// then returns the value of that index (0-255)
	return pixelData[pixelIndex * 3 + channel];
}

vector<unsigned char> Image::getChannelDataVector() const
{
	return pixelData;
}

Header Image::getHeader() const
{
	return header;
}

// mutator ---------------------------------------------

void Image::setChannel(int pixelIndex, int channel, unsigned char newPixelValue)
{
	// first calculates the index
	// then sets the pixelvalue of that channel to the newPixel value 
	pixelData[pixelIndex * 3 + channel] = newPixelValue;

}

void Image::setChannelDataVector(const vector<unsigned char>& newChannelDataVector)
{
	pixelData = newChannelDataVector;
}

void Image::setHeader(const Header& newHeader)
{
	header = newHeader;
}

// outside functions -----------------------------------

// image edit functions --------------------------------

Image multiply(const Image& img1, const Image& img2)
{
	Image result;
	result.setHeader(img1.getHeader());

	vector<unsigned char> resultVector;
	int resultWidth = result.getWidth();
	int resultHeight = result.getHeight();

	int pixelCount = resultWidth * resultHeight * 3;
	resultVector.resize(pixelCount);

	unsigned int numOfPixels = static_cast<unsigned int>(resultVector.size() / 3);

	for (unsigned int pixel = 0; pixel < numOfPixels; pixel++)
	{
		for (unsigned int channel = 0; channel < 3; channel++)
		{
			// Get img values
			float img1ChanVal = img1.getChannel(pixel, channel) / 255.0f;
			float img2ChanVal = img2.getChannel(pixel, channel) / 255.0f;
			// multiply
			float multipledImgVal = img1ChanVal * img2ChanVal;
			// normalize 
			float normalImgVal = multipledImgVal * 255.0f;
			//round
			unsigned char resultVal = static_cast<unsigned char>(normalImgVal + 0.5f);
			// assign new value to target channel
			resultVector[pixel * 3 + channel] = resultVal;

		}
	}

	result.setChannelDataVector(resultVector);
	return result;
}

// test functions --------------------------------------

bool compareImages(Image& img1, Image& img2)
{
	if (img1.getChannelDataVector() == img2.getChannelDataVector() && img1.getHeader() == img2.getHeader())
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool runSingleTest(string img1, string img2, string testNum)
{
	
	Image image1;
	image1.read(img1);

	Image image2;
	image2.read(img2);

	bool compareTest = compareImages(image1, image2);

	if (compareTest)
	{
		cout << testNum << " ......Passed!" << endl;
	}
	else
	{
		cout << testNum << " ......Failed!" << endl;
	}

	return compareTest;
}

void runAllTests()
{
	cout << endl;
	cout << "Reading all files for testing..." << endl;
	int passedCount = 0;
	
	cout << endl;
	passedCount += runSingleTest("output/part1.tga", "examples/EXAMPLE_part1.tga", "Test #1");

	cout << endl;
	cout << "Test results: " << passedCount << " / 11" << endl;

}