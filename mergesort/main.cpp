#include <iostream>
#include <cstring>

using namespace std;

void merge(int* array1, int len1, int* array2, int len2, int* result) {
    int i = 0, j = 0, k = 0;

    while (i < len1 && j < len2) {
        if (array1[i] < array2[j]) {
            result[k] = array1[i++];
        } else {
            result[k] = array2[j++];
        }
        k++;
    }

    if (i >= len1) {
        memcpy(result + k, array2 + j, sizeof(int) * (len2 - j));
    }

    if (j >= len2) {
        memcpy(result + k, array1 + i, sizeof(int) * (len1 - i));
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