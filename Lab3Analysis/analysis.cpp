#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "ABS.h"
#include "ABQ.h"
using namespace std;
using namespace chrono;

int main()
{
	vector<float> scaleFactors = { 1.5f, 2.0f, 3.0f, 10.0f, 100.0f };
	vector<int> nValues = { 10000000, 30000000, 50000000, 75000000, 100000000 };

	ofstream file("results.csv");
	file << "Task, Scale Factor, N, Time, Resizes" << endl;

	for (unsigned int scaleFactor = 0; scaleFactor < scaleFactors.size(); scaleFactor++)
	{
		for (unsigned int nValue = 0; nValue < nValues.size(); nValue++)
		{
			// RUN PUSH TASK, RECORD TIME AND RESIZES
			ABS<int> absStack(2, scaleFactors[scaleFactor]);

			auto start = high_resolution_clock::now();

			for (int n = 0; n < nValues[nValue]; n++)
			{
				absStack.push(n);
			}
			auto end = high_resolution_clock::now();
			duration<double> elapsed = end - start;
			double time = elapsed.count();

			file << "PUSH" << "," << scaleFactors[scaleFactor] << "," << nValues[nValue] << "," << time << "," << absStack.getTotalResizes() << endl;

			// RUN POP TASK, RECORD TIME AND RESIZES
			auto start_second = high_resolution_clock::now();

			for (int n = 0; n < nValues[nValue]; n++)
			{
				absStack.pop();
			}
			auto end_second = high_resolution_clock::now();
			duration<double> elapsed_second = end_second - start_second;
			double time_second = elapsed_second.count();

			file << "POP" << "," << scaleFactors[scaleFactor] << "," << nValues[nValue] << "," << time_second << "," << absStack.getTotalResizes() << endl;

			// RUN ENQUEUE TASK, RECORD TIME AND RESIZE
			ABQ<int> abqQueue(2, scaleFactors[scaleFactor]);

			auto start_third = high_resolution_clock::now();

			for (int n = 0; n < nValues[nValue]; n++)
			{
				abqQueue.enqueue(n);
			}
			auto end_third = high_resolution_clock::now();
			duration<double> elapsed_third = end_third - start_third;
			double time_third = elapsed_third.count();

			file << "ENQUEUE" << "," << scaleFactors[scaleFactor] << "," << nValues[nValue] << "," << time_third << "," << abqQueue.getTotalResizes() << endl;

			// RUN DEQUEUE TASK, RECORD TIME AND RESIZE
			auto start_fourth = high_resolution_clock::now();

			for (int n = 0; n < nValues[nValue]; n++)
			{
				abqQueue.dequeue();
			}
			auto end_fourth = high_resolution_clock::now();
			duration<double> elapsed_fourth = end_fourth - start_fourth;
			double time_fourth = elapsed_fourth.count();

			file << "DEQUEUE" << "," << scaleFactors[scaleFactor] << "," << nValues[nValue] << "," << time_fourth << "," << abqQueue.getTotalResizes() << endl;

		}
	}

}