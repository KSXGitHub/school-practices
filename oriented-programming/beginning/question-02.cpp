
#include <iostream>

using namespace std;

bool isSquareNumber(unsigned number) {
	unsigned decrement = 1;
	while (decrement < number) {
		number -= decrement;
		decrement += 2;
	}
	return decrement == number;
}

int main() {
	for (unsigned i = 1000; i != 10000; ++i) {
		if (isSquareNumber(i)) {
			cout << i << endl;
		}
	}
	return 0;
}
