
// Quy ước: Nhánh trái < Gốc < Nhánh phải

#include <iostream>
#include <cstdlib>

using namespace std;

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
void xuatChanLe(BinTree);
void xuatMinMax(BinTree);
void timGiaTri(BinTree);

BinTree createNode(Data, BinTree = NULL, BinTree = NULL);
void clearTree(BinTree &);
void addNode(BinTree &, Data);
void statOddEven(BinTree, unsigned &, unsigned &);
// void statMinMax(BinTree, Data &, Data &);
Data getMin(BinTree);
Data getMax(BinTree);
BinTree find(BinTree, Data);

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
        xuatChanLe(tree);
        xuatMinMax(tree);
        timGiaTri(tree);
        clearTree(tree);
    } else {
        cout << "Cây nhị phân rỗng, không có việc để làm.\nXin chào và hẹn gặp lại!\n";
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

void xuatChanLe(BinTree tree) {
    unsigned le = 0, chan = 0;
    statOddEven(tree, le, chan);
    cout << "Cây nhị phân có " << le << " số lẻ và " << chan << " số chẵn\n";
}

void xuatMinMax(BinTree tree) {
    cout << "min = " << getMin(tree) << endl;
    cout << "max = " << getMax(tree) << endl;
}

void timGiaTri(BinTree tree) {
    Data doituong;
    cout << "Nhập giá trị cần tìm: ";
    cin >> doituong;
    cout << "Cây nhị phân " << (find(tree, doituong) ? "CÓ" : "KHÔNG") << " CHỨA phần tử có giá trị " << doituong << endl;
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

void statOddEven(BinTree tree, unsigned &odds, unsigned &evens) {
    if (tree) {
        ++(tree->data & 1 ? odds : evens);
        statOddEven(tree->left, odds, evens);
        statOddEven(tree->right, odds, evens);
    }
}

Data getMin(BinTree tree) {
    Data min = tree->data;
    for (BinTree cmpend = tree->left; cmpend; cmpend = cmpend->left) {
        if (cmpend->data < min) {
            min = cmpend->data;
        }
    }
    return min;
}

Data getMax(BinTree tree) {
    Data max = tree->data;
    for (BinTree cmpend = tree->right; cmpend; cmpend = cmpend->right) {
        if (cmpend->data > max) {
            max = cmpend->data;
        }
    }
    return max;
}

BinTree find(BinTree tree, Data data) {
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
