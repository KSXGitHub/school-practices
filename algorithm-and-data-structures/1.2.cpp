
#include <iostream>
#include <cstdlib>

using namespace std;

const unsigned LENGTH = 255;

struct DSMang {
    unsigned soluong;
    int phantu[LENGTH];
};

int main();
void nhap(DSMang &);
void xuat(DSMang);
void chen(DSMang &, unsigned, int);
int xoa(DSMang &, unsigned);

int main() {

    // Khai báo
    DSMang danhsach;
    unsigned vitri;
    int phantu;

    // Khởi tạo Command Prompt
    system("chcp 65001");

    // Nhập mảng, Xuất mảng
    cout << "Nhập số lượng và các phần tử: ";
    nhap(danhsach);
    cout << "Danh sách đã nhập: ";
    xuat(danhsach);

    // Chèn phần tử, Xuất mảng
    cout << "Nhập vị trí phần tử cần chèn: ";
    cin >> vitri >> phantu;
    chen(danhsach, vitri, phantu);
    cout << "Danh sách sau khi chèn: ";
    xuat(danhsach);

    // Xóa phần tử, xuất mảng
    cout << "Nhập vị trí của phần tử cần xóa: ";
    cin >> vitri;
    phantu = xoa(danhsach, vitri);
    cout << "Đã xóa phần tử " << phantu << " khỏi danh sách\n";
    cout << "Danh sách sau khi xóa: ";
    xuat(danhsach);

    // Kết thúc
    return 0;

}

void nhap(DSMang &danhsach) {
    cin >> danhsach.soluong;
    for (unsigned i = 0; i != danhsach.soluong; ++i) {
        cin >> danhsach.phantu[i];
    }
}

void xuat(DSMang danhsach) {
    for (unsigned i = 0; i != danhsach.soluong; ++i) {
        cout << '\x20' << danhsach.phantu[i];
    }
    cout << endl;
}

void chen(DSMang &ds, unsigned vt, int pt) {
    for (unsigned i = ds.soluong; i != vt; --i) {
        ds.phantu[i] = ds.phantu[i - 1];
    }
    ds.phantu[vt] = pt;
    ++ds.soluong;
}

int xoa(DSMang &ds, unsigned vt) {
    int pt = ds.phantu[vt];
    --ds.soluong;
    for (unsigned i = vt; i != ds.soluong; ++i) {
        ds.phantu[i] = ds.phantu[i + 1];
    }
    return pt;
}
