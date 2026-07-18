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

Image subtract(const Image& img1, const Image& img2)
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
			// Get img values img2 = bottom, img1 = top
			int img1ChanVal = img1.getChannel(pixel, channel);
			int img2ChanVal = img2.getChannel(pixel, channel);
			// subtract
			int subtractVal = img2ChanVal - img1ChanVal;

			if (subtractVal < 0)
			{
				subtractVal = 0;
			}
			else if (subtractVal > 255)
			{
				subtractVal = 255;
			}

			unsigned char resultVal = static_cast<unsigned char>(subtractVal);

			// assign new value to target channel
			resultVector[pixel * 3 + channel] = resultVal;
		}
	}
	result.setChannelDataVector(resultVector);
	return result;
}

Image screen(const Image& img1, const Image& img2)
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
			// subtract (a, b)
			float subtractedChannelA = 1 - img1ChanVal;
			float subtractedChannelB = 1 - img2ChanVal;
			//multiply a and b
			float multipliedChannelAB = subtractedChannelA * subtractedChannelB;
			//subtract 1 - combined float
			float subtractedCombinedAB = 1 - multipliedChannelAB;
			// denormalize
			float normalImgVal = subtractedCombinedAB * 255.0f;
			//round
			unsigned char resultVal = static_cast<unsigned char>(normalImgVal + 0.5f);
			// assign new value to target channel
			resultVector[pixel * 3 + channel] = resultVal;
		}
	}
	result.setChannelDataVector(resultVector);
	return result;
}

Image overlay(const Image& img1, const Image& img2)
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

			float normalizedImgVal = 0;

			// check float b/img2
			if (img2ChanVal <= 0.5)
			{
				normalizedImgVal = 2 * img1ChanVal * img2ChanVal;
			}
			else
			{
				normalizedImgVal = 1 - 2 * (1 - img1ChanVal) * (1 - img2ChanVal);
			}

			// denormalize 
			float denormalizedImgVal = normalizedImgVal * 255.0f;
			//round
			unsigned char resultVal = static_cast<unsigned char>(denormalizedImgVal + 0.5f);
			// assign new value to target channel
			resultVector[pixel * 3 + channel] = resultVal;
		}
	}

	result.setChannelDataVector(resultVector);
	return result;
}

Image addGreen(const Image& img)
{
	Image result;
	result.setHeader(img.getHeader());

	vector<unsigned char> resultVector = img.getChannelDataVector();

	unsigned int numOfPixels = static_cast<unsigned int>(resultVector.size() / 3);

	for (unsigned int pixel = 0; pixel < numOfPixels; pixel++)
	{
		int greenChannelVal = img.getChannel(pixel, 1) + 200;

		if (greenChannelVal > 255)
		{
			greenChannelVal = 255;			
		}
		unsigned char modifiedVal = static_cast<unsigned char>(greenChannelVal);
		resultVector[pixel * 3 + 1] = modifiedVal;
	}

	result.setChannelDataVector(resultVector);
	return result;
}

Image scaleBlueRed(const Image& img)
{
	Image result;
	result.setHeader(img.getHeader());

	vector<unsigned char> resultVector = img.getChannelDataVector();

	unsigned int numOfPixels = static_cast<unsigned int>(resultVector.size() / 3);

	for (unsigned int pixel = 0; pixel < numOfPixels; pixel++)
	{
		int blueChannelVal = img.getChannel(pixel, 0) * 0;
		int redChannelVal = img.getChannel(pixel, 2) * 4;

		if (redChannelVal > 255)
		{
			redChannelVal = 255;
		}
		unsigned char blueModifiedVal = static_cast<unsigned char>(blueChannelVal);
		resultVector[pixel * 3 + 0] = blueModifiedVal;

		unsigned char redModifiedVal = static_cast<unsigned char>(redChannelVal);
		resultVector[pixel * 3 + 2] = redModifiedVal;
	}

	result.setChannelDataVector(resultVector);
	return result;
}

Image greyScaleIntensity(const Image& img, int targetChannel)
{
	Image result;
	result.setHeader(img.getHeader());

	vector<unsigned char> resultVector = img.getChannelDataVector();

	unsigned int numOfPixels = static_cast<unsigned int>(resultVector.size() / 3);

	for (unsigned int pixel = 0; pixel < numOfPixels; pixel++)
	{
		int targetChannelVal = img.getChannel(pixel, targetChannel);

		for (unsigned int channel = 0; channel < 3; channel++)
		{
			if (channel != targetChannel)
			{
				unsigned char modifiedVal = static_cast<unsigned char>(targetChannelVal);
				resultVector[pixel * 3 + channel] = modifiedVal;
			}
		}
	}

	result.setChannelDataVector(resultVector);
	return result;
}

Image combineRGB(const Image& img1, const Image& img2, const Image& img3)
{
	Image result;
	result.setHeader(img1.getHeader());

	vector<unsigned char> resultVector = img1.getChannelDataVector();

	unsigned int numOfPixels = static_cast<unsigned int>(resultVector.size() / 3);

	for (unsigned int pixel = 0; pixel < numOfPixels; pixel++)
	{
		// blue -----
		int blueChannelVal = img1.getChannel(pixel, 0);

		unsigned char blueModifiedVal = static_cast<unsigned char>(blueChannelVal);
		resultVector[pixel * 3 + 0] = blueModifiedVal;

		// green ----
		int greenChannelVal = img2.getChannel(pixel, 1);
		
		unsigned char greenModifiedVal = static_cast<unsigned char>(greenChannelVal);
		resultVector[pixel * 3 + 1] = greenModifiedVal;
		
		// red ------
		int redChannelVal = img3.getChannel(pixel, 2);

		unsigned char redModifiedVal = static_cast<unsigned char>(redChannelVal);
		resultVector[pixel * 3 + 2] = redModifiedVal;
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
	passedCount += runSingleTest("output/part2.tga", "examples/EXAMPLE_part2.tga", "Test #2");
	passedCount += runSingleTest("output/part3.tga", "examples/EXAMPLE_part3.tga", "Test #3");
	passedCount += runSingleTest("output/part4.tga", "examples/EXAMPLE_part4.tga", "Test #4");
	passedCount += runSingleTest("output/part5.tga", "examples/EXAMPLE_part5.tga", "Test #5");
	passedCount += runSingleTest("output/part6.tga", "examples/EXAMPLE_part6.tga", "Test #6");
	passedCount += runSingleTest("output/part7.tga", "examples/EXAMPLE_part7.tga", "Test #7");
	passedCount += runSingleTest("output/part8_r.tga", "examples/EXAMPLE_part8_r.tga", "Test #8a");
	passedCount += runSingleTest("output/part8_g.tga", "examples/EXAMPLE_part8_g.tga", "Test #8b");
	passedCount += runSingleTest("output/part8_b.tga", "examples/EXAMPLE_part8_b.tga", "Test #8c");
	passedCount += runSingleTest("output/part9.tga", "examples/EXAMPLE_part9.tga", "Test #9");

	cout << endl;
	cout << "Test results: " << passedCount << " / 13" << endl;

}