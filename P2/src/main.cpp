#include <iostream>
#include "image.h"
using namespace std;

// task functions -----------

void task1()
{
	Image img1;
	Image img2;

	img1.read("input/layer1.tga");
	img2.read("input/pattern1.tga");

	Image result = multiply(img1, img2);

	result.write("output/part1.tga");

	cout << "Task 1 complete" << endl;
}


int main()
{
	task1();

	runAllTests();

	return 0;
}
