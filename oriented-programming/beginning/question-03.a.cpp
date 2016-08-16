
#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

void sort(int *array, unsigned length) {
	for (unsigned i = 0, ie = length - 1; i != ie; ++i) {
		for (unsigned j = i + 1; j != length; ++j) {
			if (array[i] > array[j]) {
				swap(array[i], array[j]);
			}
		}
	}
}

int *enterArray(unsigned length) {
	int *array = new int[length];
	for (unsigned i = 0; i != length; ++i) {
		cin >> array[i];
	}
	return array;
}

void printArray(int *array, unsigned length) {
	for (unsigned i = 0; i != length; ++i) {
		cout << array[i] << ' ';
	}
}

int main() {
	cout << "Nhap lan luot so luong va cac phan tu: ";
	unsigned length;
	cin >> length;
	int *array = enterArray(length);
	sort(array, length);
	cout << "Mang da sap xep: ";
	printArray(array, length);
	delete[] array;
	return 0;
}
