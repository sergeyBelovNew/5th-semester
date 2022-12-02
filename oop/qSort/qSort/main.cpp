#include <iostream>
#include <algorithm>

using namespace std;

void sortBubble(int* array, int size, int& counterIter);
void sortHoare(int* array, int size, int& counterIter);
void outputMas(int* array, int lenght, int counterIter);

int main() {
    int numElements = 1000;
    int counterIter = 0;
    int counterIter2 = 0;
    int* massive = new int[numElements];
    for (int i = 0; i < numElements; i++) {
        massive[i] = rand() % 1225;
    }
    sortBubble(massive, numElements, counterIter);
    sortHoare(massive, numElements, counterIter2);
    outputMas(massive, numElements, counterIter2);
   
    return 0;
}

void sortBubble(int* array, int size, int &counterIter) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                counterIter++;
            }
        }
    }

    outputMas(array, size, counterIter);
}

void sortHoare(int* array, int size, int &counterIter) {
    int begin = 0;
    int end = size - 1;
    int mid = array[size / 2];

    while (begin <= end){

        while (array[begin] < mid) {
            begin++;
        }

        while (array[end] > mid) {
            end--;
        }

        if (begin <= end) {
            counterIter++;
            swap(array[begin], array[end]);
            begin++;
            end--;
        }
    }

    if (end > 0) {
        counterIter++;
        sortHoare(array, end + 1, counterIter);
    }
    if (begin < size) {
        counterIter++;
        sortHoare(&array[begin], size - begin, counterIter);
    }
}

void outputMas(int* array, int lenght, int counterIter) {
    cout << "\n\nCounter iteration: " << counterIter << "\n";
	for (int i = 0; i < lenght; i++) {
		cout << array[i] << "  ";
	}
}
