
#include <iostream>

using namespace std;

const unsigned DIGITS = 5;
typedef char Operand[DIGITS + 1];
typedef char Sum[DIGITS + 1 + 1];

void enterOperand(Operand number) {
	cin.getline(number, DIGITS + 1);
}

void sumOperand(Sum r, Operand a, Operand b) {
	char cache = 0;
	for (int i = DIGITS - 1; i >= 0; --i) {
		char sum = a[i] - '0' + b[i] - '0' + cache;
		r[i + 1] = sum % 10 + '0';
		cache = sum >= 10;
	}
	r[0] = cache + '0';
	r[DIGITS + 2] = '\0';
}

int main() {
	Operand a, b;
	Sum r;
	cout << "Nhap so thu nhat: ";
	enterOperand(a);
	cout << "Nhap so thu hai: ";
	enterOperand(b);
	sumOperand(r, a, b);
	cout << "Tong: " << r << endl;
	return 0;
}
