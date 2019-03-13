#include <iostream>
#include <cstring>

using namespace std;

int factorial(int value) {
	int result = value;

	for (int i = value - 1; i > 0; i--) {
		result *= i;
	}

	return result;
}

int recursiveFactorial(int value) {
	if (value == 1) {
		return 1;
	}

	return value * recursiveFactorial(value - 1);
}

void merge(int* array1, int len1, int* array2, int len2, int* result) 
{
	int i = 0, j = 0, k = 0;

	while (i < len1 && j < len2)
	{
		if (array1[i] < array2[j])
		{
			result[k] = array1[i++];
		}
		else
		{
			result[k] = array2[j++];
		}

		k++;
	}

	if (i >= len1) 
	{
		for (int index = k; index < len1 + len2; index++)
		{
			result[index] = array2[j++];
		}
	}
	else if (j >= len2)
	{
		for (int index = k; index < len1 + len2; index++)
		{
			result[index] = array1[i++];
		}
	}
}

void mergeSort(int* array, int length) {
	if (length <= 1) {
		return;
	}

	int firstLength = length / 2;
	int secondLength = length - firstLength;

	mergeSort(array, firstLength);
	mergeSort(array + firstLength, secondLength);

	int* result = new int[length];

	merge(array, firstLength, array + firstLength, secondLength, result);
	memcpy(array, result, sizeof(int) * length);	

	delete[] result;
}

int main(void) {
	int size = 0;

	cout << ">> ";
	cin >> size;

	int* array = new int[size];

	cout << ">> ";
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}

	mergeSort(array, size);

	cout << ">> ";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}

	cout << endl;

	delete[] array;

	return 0;
}