
#include <iostream>

using namespace std;

struct ToaDo {
    unsigned x, y;
    bool operator==(ToaDo o) {
        return x == o.x && y == o.y;
    }
};

struct MaTran {
    static const unsigned MAXSZ = 255;
    unsigned sohang, socot;
    int phantu[MAXSZ][MAXSZ];
    int operator[](ToaDo toado) {
        return phantu[toado.x][toado.y];
    }
};

struct DSToaDo {
    unsigned soluong;
    ToaDo phantu[MaTran::MAXSZ];
    DSToaDo () {
        soluong = 0;
    }
    void them (ToaDo toado) {
        phantu[soluong] = toado;
        ++soluong;
    }
};

int main();
void nhap(MaTran &);
void xuat(MaTran);
DSToaDo yenngua(MaTran);
void xuat(DSToaDo, MaTran);
DSToaDo maxhang(MaTran);
DSToaDo mincot(MaTran);
DSToaDo giao(DSToaDo, DSToaDo);

int main() {
    MaTran matran;
    cout << "Nhập lần lượt số hàng, số cột, và các phần tử của ma trận:\n";
    nhap(matran);
    cout << "Ma trận đã nhập:\n";
    xuat(matran);
    cout << "Các điểm yên ngựa:\n";
    xuat(yenngua(matran), matran);
    return 0;
}

void nhap(MaTran &matran) {
    cin >> matran.sohang >> matran.socot;
    for (unsigned i = 0; i != matran.sohang; ++i) {
        for (unsigned j = 0; j != matran.socot; ++j) {
            cin >> matran.phantu[i][j];
        }
    }
}

void xuat(MaTran matran) {
    for (unsigned i = 0; i != matran.sohang; ++i) {
        for (unsigned j = 0; j != matran.socot; ++j) {
            cout << ' ' << matran.phantu[i][j];
        }
        cout << endl;
    }
}

DSToaDo yenngua(MaTran matran) {
    return giao(maxhang(matran), mincot(matran));
}

void xuat(DSToaDo toado, MaTran matran) {
    for (unsigned i = 0; i != toado.soluong; ++i) {
        ToaDo vitri = toado.phantu[i];
        cout << "matran[" << vitri.x << ", " << vitri.y << "] = ";
        cout << matran[vitri] << endl;
    }
}

DSToaDo maxhang(MaTran matran) {
    DSToaDo ds;
    for (unsigned i = 0; i != matran.sohang; ++i) {
        int max = matran.phantu[i][0];
        for (unsigned j = 1; j != matran.socot; ++j) {
            if (max < matran.phantu[i][j]) {
                max = matran.phantu[i][j];
            }
        }
        for (unsigned j = 0; j != matran.socot; ++i) {
            if (max == matran.phantu[i][j]) {
                ToaDo moi = {i, j};
                ds.them(moi);
            }
        }
    }
    return ds;
}

DSToaDo mincot(MaTran matran) {
    DSToaDo ds;
    for (unsigned i = 0; i != matran.socot; ++i) {
        int min = matran.phantu[0][i];
        for (unsigned j = 1; j != matran.sohang; ++j) {
            if (min > matran.phantu[j][i]) {
                min = matran.phantu[j][i];
            }
        }
        for (unsigned j = 0; j != matran.sohang; ++i) {
            if (min == matran.phantu[j][i]) {
                ToaDo moi = {j, i};
                ds.them(moi);
            }
        }
    }
    return ds;
}

DSToaDo giao(DSToaDo A, DSToaDo B) {
    DSToaDo ds;
    for (unsigned i = 0; i != A.soluong; ++i) {
        for (unsigned j = 0; j != B.soluong; ++j) {
            if (A.phantu[i] == A.phantu[j]) {
                ds.them(A.phantu[i]);
                break;
            }
        }
    }
    return ds;
}
