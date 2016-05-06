
#include <iostream>

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

    // Nhập mảng, Xuất mảng
    cout << "Nhap so luong va cac phan tu: ";
    nhap(danhsach);
    cout << "Danh sach da nhap: ";
    xuat(danhsach);

    // Chèn phần tử, Xuất mảng
    cout << "Nhap vi tri, phan tu can chen: ";
    cin >> vitri >> phantu;
    chen(danhsach, vitri, phantu);
    cout << "Danh sach sau khi chen: ";
    xuat(danhsach);

    // Xóa phần tử, xuất mảng
    cout << "Nhap vi tri cua phan tu can xoa: ";
    cin >> vitri;
    phantu = xoa(danhsach, vitri);
    cout << "Da xoa phan tu " << phantu << " khoi danh sach\n";
    cout << "Danh sach sau khi xoa: ";
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
