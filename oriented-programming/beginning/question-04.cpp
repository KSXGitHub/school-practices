
#include <iostream>

using namespace std;

enum CompareResult {
	LESS = -1,
	EQUAL = 0,
	GREATER = +1
};

CompareResult compare(int *a, int *b, unsigned length) {
	for (unsigned i = 0; i != length; ++i) {
		if (a[i] < b[i]) return LESS;
		if (a[i] > b[i]) return GREATER;
	}
	return EQUAL;
}

int *enterArray(unsigned length) {
	int *array = new int[length];
	for (unsigned i = 0; i != length; ++i) {
		cin >> array[i];
	}
	return array;
}

int main() {
	unsigned length;
	cout << "Nhap do dai: ";
	cin >> length;
	cout << "Nhap mang thu nhat: ";
	int *a = enterArray(length);
	cout << "Nhap mang thu hai: ";
	int *b = enterArray(length);
	switch (compare(a, b, length)) {
		case LESS:
			cout << "Mang thu hai lon hon\n";
			break;
		case GREATER:
			cout << "Mang thu nhat lon hon\n";
			break;
		default:
			cout << "Hai mang giong nhau\n";
	}
	delete[] a;
	delete[] b;
	return 0;
}
