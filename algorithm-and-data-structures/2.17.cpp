
// Quy ước:
//  * Nhánh trái < Gốc < Nhánh phải
//  * Gốc của một cây nhị phân có mức bằng 0

#include <iostream>
#include <cstdlib>

using namespace std;

/* CONSTANTS */

const unsigned BITLENGTH_INT = sizeof(int) * 8;
const int MIN_INT = 1u << (BITLENGTH_INT - 1);
const int MAX_INT = ~MIN_INT;

/* TYPES AND CLASSES */

typedef int Data;
struct Node;
typedef Node *BinTree;

struct Node {
    Data data;
    BinTree left, right;
};

/* FUNCTION PROTOTYPES */

int main();
void nhap(BinTree &);
void xuat(BinTree, unsigned = 0);
void xuatCayConLonNhat(BinTree);
void xuatNutLaSauNhat(BinTree);

BinTree createNode(Data, BinTree = NULL, BinTree = NULL);
void clearTree(BinTree &);
void addNode(BinTree &, Data);
void findMaxTotalSubTree(BinTree, BinTree &, Data &, Data &);
void findDeepestLeaf(BinTree, unsigned, BinTree &, unsigned &);

/* FUNCTION DEFINITIONS */

// MAIN PROGRAM

int main() {
    BinTree tree = NULL;
    system("chcp 65001");
    cout << "Nhập lần lượt số lượng và các giá trị để thêm vào cây nhị phân: ";
    nhap(tree);
    if (tree) {
        cout << "Cây nhị phân đã nhập:\n";
        xuat(tree);
        xuatCayConLonNhat(tree);
        xuatNutLaSauNhat(tree);
        clearTree(tree);
    } else {
        cout << "Cây nhị phân rỗng, những thao tác tiếp theo không còn cần thiết\nTạm biệt!\n";
    }
    return 0;
}

void nhap(BinTree &tree) {
    unsigned soluong;
    for (cin >> soluong; soluong; --soluong) {
        Data newnode;
        cin >> newnode;
        addNode(tree, newnode);
    }
}

void xuat(BinTree tree, unsigned muc) {
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

void xuatCayConLonNhat(BinTree tree) {
    BinTree lonnhat;
    Data tong, __dem;
    findMaxTotalSubTree(tree, lonnhat, tong, __dem);
    cout << "Cây (nhánh cây) lớn nhất có gốc chứa giá trị " << lonnhat->data << " và có tổng bằng " << tong << endl;
}

void xuatNutLaSauNhat(BinTree tree) {
    BinTree saunhat;
    unsigned muc;
    findDeepestLeaf(tree, 0, saunhat, muc);
    cout << "Nút lá sâu nhất có giá trị " << saunhat->data << " và nằm ở mức " << muc << endl;
}

// FUNCTIONS

BinTree createNode(Data data, BinTree left, BinTree right) {
    BinTree newnode = new Node();
    newnode->data = data;
    newnode->left = left;
    newnode->right = right;
    return newnode;
}

void clearTree(BinTree &tree) {
    if (tree) {
        clearTree(tree->left);
        clearTree(tree->right);
        delete tree;
        tree = NULL;
    }
}

void addNode(BinTree &tree, Data newnode) {
    BinTree *ptr = &tree;
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

void findMaxTotalSubTree(BinTree origin, BinTree &biggest, Data &max, Data &total) {
    if (origin) {
        BinTree lbiggest, rbiggest;
        Data lmax, ltotal, rmax, rtotal;
        findMaxTotalSubTree(origin->left, lbiggest, lmax, ltotal);
        findMaxTotalSubTree(origin->right, rbiggest, rmax, rtotal);
        biggest = origin;
        max = total = origin->data + ltotal + rtotal;
        if (lmax > max) {
            biggest = origin->left;
            max = lmax;
        }
        if (rmax > max) {
            biggest = origin->right;
            max = rmax;
        }
    } else {
        total = 0;
        max = MIN_INT;
    }
}

void findDeepestLeaf(BinTree origin, unsigned originlevel, BinTree &deepest, unsigned &deepestlevel) {
    if (origin->left) {
        if (origin->right) {
            BinTree ld, rd;
            unsigned ldlv, rdlv;
            findDeepestLeaf(origin->left, originlevel + 1, ld, ldlv);
            findDeepestLeaf(origin->right, originlevel + 1, rd, rdlv);
            if (ldlv > rdlv) {
                deepest = ld;
                deepestlevel = ldlv;
            } else {
                deepest = rd;
                deepestlevel = rdlv;
            }
        } else {
            findDeepestLeaf(origin->left, originlevel + 1, deepest, deepestlevel);
        }
    } else {
        if (origin->right) {
            findDeepestLeaf(origin->right, originlevel + 1, deepest, deepestlevel);
        } else {
            deepest = origin;
            deepestlevel = originlevel;
        }
    }
}
