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

short Image::getWidth()
{
	return header.imageWidth;
}

short Image::getHeight()
{
	return header.imageHeight;
}