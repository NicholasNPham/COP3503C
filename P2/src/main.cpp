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

void task3()
{
	Image img1;
	Image img2;
	Image img3;
	
	img1.read("input/layer1.tga");
	img2.read("input/pattern2.tga");
	img3.read("input/text.tga");

	Image tempImg = multiply(img1, img2);

	Image result = screen(tempImg, img3);

	result.write("output/part3.tga");

	cout << "Task 3 complete" << endl;

}

void task4()
{
	Image img1;
	Image img2;
	Image img3;

	img1.read("input/layer2.tga");
	img2.read("input/circles.tga");
	img3.read("input/pattern2.tga");

	Image tempImg = multiply(img1, img2);
	Image result = subtract(img3, tempImg);

	result.write("output/part4.tga");

	cout << "Task 4 complete" << endl;
}

void task5()
{
	Image img1;
	Image img2;

	img1.read("input/layer1.tga");
	img2.read("input/pattern1.tga");

	Image result = overlay(img1, img2);

	result.write("output/part5.tga");
	
	cout << "Task 5 complete" << endl;
}

void task6()
{
	Image img;
	img.read("input/car.tga");

	Image result = addGreen(img);

	result.write("output/part6.tga");

	cout << "Task 6 complete" << endl;
}

void task7()
{
	Image img;
	img.read("input/car.tga");

	Image result = scaleBlueRed(img);

	result.write("output/part7.tga");

	cout << "Task 7 complete" << endl;
}

int main()
{
	task1();
	task2();
	task3();
	task4();
	task5();
	task6();
	task7();

	runAllTests();

	return 0;
}
