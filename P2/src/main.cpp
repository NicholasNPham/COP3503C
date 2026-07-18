#include <iostream>
#include "image.h"
using namespace std;

// just for testing
void testReadWrite()
{
	Image image1;
	image1.read("input/car.tga");

	cout << "Height: " << image1.getHeight() << endl;
	cout << "Width: " << image1.getWidth() << endl;

	image1.write("output/car_copy.tga");

	Image image2;
	image2.read("output/car_copy.tga");


	cout << compareImages(image1, image2) << endl;


	runAllTests();
}


int main()
{


	return 0;
}
