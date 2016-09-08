
#include <iostream>

using namespace std;

int greedy (int *menhgia, int vitri, int tien) {
	if (tien) {
		return tien / menhgia[vitri] + greedy(menhgia, vitri - 1, tien % menhgia[vitri]);
	}
	return 0;
}

void swap (int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

void sapxep (int *mang, int soluong) {
	for (int i = 0; i != soluong; ++i) {
		for (int j = i; j != soluong; ++j) {
			if (mang[i] > mang[j]) {
				swap(mang[i], mang[j]);
			}
		}
	}
}

void nhap (int *&menhgia, int &soluong, int &sotien) {
	cout << "Nhập số tiền: ";
	cin >> sotien;
	cout << "Nhập số lượng và các mệnh giá: ";
	cin >> soluong;
	menhgia = new int[soluong];
	for (int i = 0; i != soluong; ++i) {
		cin >> menhgia[i];
	}
}

void xuat (int *mang, int soluong) {
	for (int i = 0; i != soluong; ++i) {
		cout << mang[i] << ' ';
	}
	cout << endl;
}

int main () {
	int *menhgia, soluong, sotien;
	nhap(menhgia, soluong, sotien);
	sapxep(menhgia, soluong);
	xuat(menhgia, soluong);
	int soto = greedy(menhgia, soluong - 1, sotien);
	cout << "Số tờ: " << soto << endl;
	delete[] menhgia;
	return 0;
}
