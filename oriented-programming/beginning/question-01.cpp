
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
	unsigned number;
	cout << "Nhap mot so tu nhien: ";
	cin >> number;
	cout << number << (isSquareNumber(number) ? "" : " khong phai") << " la mot so chinh phuong.\n";
	return 0;
}
