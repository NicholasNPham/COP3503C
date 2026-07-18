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

void task2()
{
	Image img1;
	Image img2;

	img1.read("input/layer2.tga");
	img2.read("input/car.tga");

	Image result = subtract(img1, img2);

	result.write("output/part2.tga");

	cout << "Task 2 complete" << endl;
}

int main()
{
	task1();
	task2();

	runAllTests();

	return 0;
}
