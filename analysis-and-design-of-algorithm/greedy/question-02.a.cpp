
#include <iostream>

using namespace std;

struct DoanThang {
	int a, b;
	DoanThang () {}
	DoanThang (int a, int b) {
		if (a < b) {
			this->a = a;
			this->b = b;
		} else {
			this->a = b;
			this->b = a;
		}
	}
};

void swap (DoanThang &a, DoanThang &b) {
	DoanThang c = a;
	a = b;
	b = c;
}

bool trung (DoanThang doanthang, DoanThang *taphop, int soluong) {
	for (int i = 0; i != soluong; ++i) {
		if (doanthang.a < taphop[i].b && doanthang.b > taphop[i].a) {
			return true;
		}
	}
	return false;
}

void luachon (DoanThang *toanbo, int soluong, DoanThang *&chon, int &dachon) {
	chon = new DoanThang[soluong];
	dachon = 0;
	for (int i = 0; i != soluong; ++i) {
		if (!trung(toanbo[i], chon, dachon)) {
			chon[dachon] = toanbo[i];
			++dachon;
		}
	}
}

void sapxep (DoanThang *mang, int soluong) {
	for (int i = 0; i != soluong; ++i) {
		for (int j = i; j != soluong; ++j) {
			if (mang[i].b - mang[i].a > mang[j].b - mang[j].a) {
				swap(mang[i], mang[j]);
			}
		}
	}
}

void nhap (DoanThang *&mang, int &soluong) {
	cout << "Nhập số lượng và các đoạn thẳng: ";
	cin >> soluong;
	mang = new DoanThang[soluong];
	for (int i = 0; i != soluong; ++i) {
		int a, b;
		cin >> a >> b;
		mang[i] = DoanThang(a, b);
	}
}

void xuat (DoanThang *mang, int soluong) {
	for (int i = 0; i != soluong; ++i) {
		cout << mang[i].a << ' ' << mang[i].b << "; ";
	}
}

int main () {
	DoanThang *mang, *chon;
	int soluong, dachon;
	nhap (mang, soluong);
	sapxep(mang, soluong);
	luachon(mang, soluong, chon, dachon);
	cout << "Đã lựa chọn: ";
	xuat(chon, dachon);
	return 0;
}
