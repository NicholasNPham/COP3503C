#include <iostream>
#include "image.h"
using namespace std;

int main()
{
	Image image1;
	image1.read("input/car.tga");

	cout << "Height: " << image1.getHeight() << endl;
	cout << "Width: " << image1.getWidth() << endl;

	return 0;
}


