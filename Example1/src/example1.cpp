#define BUFF_SIZE 10
#include <iostream>
#include <stdexcept>

#include "array.hpp"

using namespace std;

void printArray(const Array &array, const char *prefix = NULL)
{

	if (prefix != NULL)
		cout << prefix << " ";

	for (int idx = 0; idx < array.getSize(); idx++)
	{
		cout << "[" << array[idx] << "] ";
	}

	cout << endl;
}

int main(int argc, const char *argv[])
{

	try
	{
		int arr[BUFF_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

		Array array(arr, BUFF_SIZE);

		array[2] = 100;

		printArray(array, "array");

		Array* array2 = new Array();

		*array2 = array;

		printArray(*array2, "array2");

		cout << array[100] << endl;
	}
	catch (const exception &ex)
	{
		cerr << "ERROR : " << ex.what() << endl;
	}

	return 0;
}
