
#include <iostream>
#include <algorithm>

using namespace std;

struct DoVat {
	double value, weight;
	DoVat (double value = 0, double weight = 1) {
		this->value = value;
		this->weight = weight;
	}
};

int main();
double luachon (DoVat *, int, DoVat *, int &, double);
void sapxep (DoVat *, int);

double luachon (DoVat *nguon, int soluongnguon, DoVat *dich, int &soluongdich, double gioihan) {
	int dangxet = 0;
	double tonggiatri = 0, tongtrongluong = 0;
	while (tongtrongluong < gioihan && dangxet != soluongnguon) {
		tonggiatri += nguon[dangxet].value;
		tongtrongluong += nguon[dangxet].weight;
		++dangxet;
	}
	return tonggiatri;
}
