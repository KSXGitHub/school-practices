
// Quy ước:
//  * Nhánh trái < Gốc < Nhánh phải
//  * Gốc của một cây nhị phân có mức bằng 0

#include <iostream>
#include <cstdlib>

using namespace std;

/* TYPES AND CLASSES */

typedef int DATA;
struct NODE;
typedef NODE *TREE;

struct NODE {
    DATA data;
    TREE left, right;
};

/* FUNCTION PROTOTYPES */

int main();
void nhap(TREE &);
void xuat(TREE, unsigned = 0);
void timPhanTu(TREE);
void demPhanTu(TREE);

TREE createNode(DATA, TREE = NULL, TREE = NULL);
void clearTree(TREE &);
void addNode(TREE &, DATA);
TREE find(TREE, DATA);
unsigned countGreater(TREE, DATA);

/* FUNCTION DEFINITIONS */

int main() {
    TREE tree = NULL;
    system("chcp 65001");
    cout << "Nhập số lượng và các phần tử của Cây nhị phân: ";
    nhap(tree);
    if (tree) {
        cout << "Cây nhị phân đã nhập: ";
        xuat(tree);
        timPhanTu(tree);
        demPhanTu(tree);
        clearTree(tree);
    } else {
        cout << "Cây nhị phân không tồn tại, mọi tác vụ về sau là vô nghĩa - được bỏ qua.\nXin chào và hẹn gặp lại!\n";
    }
    return 0;
}

void nhap(TREE &tree) {
    unsigned soluong;
    for (cin >> soluong; soluong; --soluong) {
        DATA newnode;
        cin >> newnode;
        addNode(tree, newnode);
    }
}

void xuat(TREE tree, unsigned muc) {
    cout << ">\t";
    for (unsigned dem = muc; dem; --dem) {
        cout << '\t';
    }
    if (tree) {
        cout << tree->data << endl;
        xuat(tree->left, muc + 1);
        xuat(tree->right, muc + 1);
    } else {
        cout << "null\n";
    }
}

void timPhanTu(TREE tree) {
    DATA phantu;
    cout << "Nhập phần tử cần tìm: ";
    cin >> phantu;
    TREE ketqua = find(tree, phantu);
    if (ketqua) {
        cout << "Tìm thấy phần tử " << phantu << " tại ô nhớ " << ketqua << endl;
    } else {
        cout << "Không tìm thấy phần tử " << phantu << " trên cây nhị phân\n";
    }
}

void demPhanTu(TREE tree) {
    DATA khoa;
    cout << "Nhập khóa: ";
    cin >> khoa;
    cout << "Cây nhị phân có " << countGreater(tree, khoa) << " có giá trị lớn hơn " << khoa << endl;
}

TREE createNode(DATA data, TREE left, TREE right) {
    TREE newnode = new NODE();
    newnode->data = data;
    newnode->left = left;
    newnode->right = right;
    return newnode;
}

void clearTree(TREE &tree) {
    if (tree) {
        clearTree(tree->left);
        clearTree(tree->right);
        delete tree;
        tree = NULL;
    }
}

void addNode(TREE &tree, DATA newnode) {
    TREE *ptr = &tree;
    while (*ptr) {
        if (newnode < (*ptr)->data) {
            ptr = &(*ptr)->left;
        } else if (newnode > (*ptr)->data) {
            ptr = &(*ptr)->right;
        } else {
            return;
        }
    }
    *ptr = createNode(newnode);
}

TREE find(TREE tree, DATA data) {
    while (tree) {
        if (data < tree->data) {
            tree = tree->left;
        } else if (data > tree->data) {
            tree = tree->right;
        } else {
            return tree;
        }
    }
    return NULL;
}

unsigned countGreater(TREE tree, DATA key) {
    if (tree) {
        if (tree->data < key) {
            return 0;
        }
        return
            countGreater(tree->left, key) +
            countGreater(tree->right, key) +
            unsigned(tree->data > key)
        ;
    }
    return 0;
}
