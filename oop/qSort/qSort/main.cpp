#include <iostream>

using namespace std;

void qSortRecursive(int* mas, int size) {
    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];

    while (i <= j){

        while (mas[i] < mid) {
            i++;
        }

        while (mas[j] > mid) {
            j--;
        }

        if (i <= j) {
            swap(mas[i], mas[j]);
           
            i++;
            j--;
        }
    }

    if (j > 0) {
        qSortRecursive(mas, j + 1);
    }
    if (i < size) {
        qSortRecursive(&mas[i], size - i);
    }
}

void outputMas(int mas[], int lenght) {
	
	for (int i = 0; i < lenght; i++) {
		cout << mas[i] << "  ";
	}
}

int main() {
	int numElements;
	cin >> numElements;
	int* massive = new int[numElements];
	for (int i = 0; i < numElements; i++) {
		massive[i] = rand()%1225;
	}
	outputMas(massive, numElements);
    qSortRecursive(massive, numElements);
    cout << "\n";
    outputMas(massive, numElements);
	return 0;
}