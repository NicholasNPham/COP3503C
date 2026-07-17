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
	pixels.resize(pixelCount);
	// PASS RAW POINTER TO FILE.READ()
	// Starts with pixel[0] pixel[786431]
	file.read(reinterpret_cast<char*>(pixels.data()), pixelCount);


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

	file.write(reinterpret_cast<char*>(pixels.data()), pixels.size());

	cout << "Write Operation Successful" << endl;
	return true;
}

// accessors -------------------------------------------
short Image::getWidth()
{
	return header.imageWidth;
}

short Image::getHeight()
{
	return header.imageHeight;
}

vector<unsigned char> Image::getPixelVector()
{
	return pixels;
}

Header Image::getHeader()
{
	return header;
}

// outside functions -----------------------------------

bool compareImages(Image& img1, Image& img2)
{
	if (img1.getPixelVector() == img2.getPixelVector() && img1.getHeader() == img2.getHeader())
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
	int passedCount = 0;
	
	passedCount += runSingleTest("output/car_copy.tga", "input/car.tga", "Test #2");


	cout << "Test results: " << passedCount << " / 11" << endl;

}