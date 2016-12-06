#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

#include "sorts.h"

#define STATIC_SIZE 40000					// Size of static array.
#define SIZE 1000									// Size of array.
#define COUNT 5000								// Number of times to sort array.
#define isascending(a,b) b>=a?1:0	// Check if 2 values are ascending.

void create_list(int a[], int test_data[]);
bool is_sorted(int a[], int size);
int get_random(int min, const int max);
int main(int argC, char** argV)
{
	int data[SIZE];					// Random data.
	int test[SIZE];					// Data to be sorted.
	int size = 100;					// Sort counter.
	int count = 0;					// Variable to count
	clock_t sortTime = 0;		// Sort timer.
	clock_t oTime = 0;			// Overhead timer.
	double duration = 0.00;	// Total time of sort.
	Algorithms algs;				// Algorithm object.

	// Seed random number generator with real time.
	srand(unsigned(time(NULL)));

	// Outer data sweep.
	for (int pass = 0; pass < 10; ++pass)
	{
		// Populate data array with random numbers, start sort counter and overhead timer.
		for (int i = 0; i < size; ++i)
			data[i] = get_random(0, SIZE);
		count = COUNT;
		oTime = clock();

		// Populate test array with random data and reset sort counter.
		while (count--)
			for (int i = 0; i < size; ++i)
				test[i] = data[i];

		// Get the difference in time for overhead. and start sort timer.
		oTime = clock() - oTime;
		count = COUNT;

		sortTime = clock();
		while (count--)
		{
			for (int i = 0; i < size; i++)
				test[i] = data[i];
			algs.mergeSort(test, 0, SIZE);
		}
		sortTime = clock() - sortTime;

		// Calculate time.
		duration = double((sortTime - oTime)) / CLOCKS_PER_SEC;
		cout << "Time to sort " << size << " items " << COUNT << " times: ";
		cout << fixed << setprecision(5) << duration << " seconds." << endl;
		if (is_sorted(test, SIZE))
		  cout << "Passed sorted test!" << endl << endl;
		else
		  cout << "Failed test!" << endl << endl;
		size += 100;
	}

	// Open file and assert existence.
	ifstream file_data("test_data.dat");
	if ( !file_data.good() )
	{
		cerr << "Error opening file. Program ended.";
		exit(1);
	}

	clock_t start, end;
	int static_test[STATIC_SIZE];
	int static_data[STATIC_SIZE];

	for (int i = 0; i < STATIC_SIZE; ++i)
	  file_data >> static_data[i];
	file_data.close();

	create_list(static_test, static_data);
	start = clock();
	algs.mergeSort(static_test, 0, STATIC_SIZE);
	end = clock();
	duration = double((end - start)) / CLOCKS_PER_SEC;
	cout << "Merge sort" << endl
		<< "Time to sort " << STATIC_SIZE << " items " << 1 << " time: "
		<< fixed << setprecision(5) << duration << " seconds." << endl;
	if (is_sorted(static_test, STATIC_SIZE))
	  cout << "Passed sorted test!" << endl << endl;
	else
	  cout << "Failed test!" << endl << endl;

	create_list(static_test, static_data);
	start = clock();
	algs.bubbleSort(static_test, STATIC_SIZE);
	end = clock();
	duration = double((end - start)) / CLOCKS_PER_SEC;
	cout << "Bubble sort" << endl
		<< "Time to sort " << STATIC_SIZE << " items " << 1 << " time: "
		<< fixed << setprecision(5) << duration << " seconds." << endl;
	if (is_sorted(static_test, STATIC_SIZE))
	  cout << "Passed sorted test!" << endl << endl;
	else
	  cout << "Failed test!" << endl << endl;

	create_list(static_test, static_data);
	start = clock();
	algs.modifiedBubbleSort(static_test, STATIC_SIZE);
	end = clock();
	duration = double((end - start)) / CLOCKS_PER_SEC;
	cout << "Modified Bubble Sort" << endl
		<< "Time to sort " << STATIC_SIZE << " items " << 1 << " time: "
		<< fixed << setprecision(5) << duration << " seconds." << endl;
	if (is_sorted(static_test, STATIC_SIZE))
	  cout << "Passed sorted test!" << endl << endl;
	else
	  cout << "Failed test!" << endl << endl;

	return EXIT_SUCCESS;
}

int get_random(int min, const int max)
{
	return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min + 1) + min;
}

bool is_sorted(int a[], int size)
{
  for (int i = 0; i < size; i++)
    if (!(isascending(a[i], a[i+1])))
      return false;
  return true;
}

void create_list(int a[], int test_data[])
{
	for (int i = 0; i < STATIC_SIZE; ++i)
		a[i] = test_data[i];
}
