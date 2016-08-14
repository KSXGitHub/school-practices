
// Quy ước: Nhánh trái < Gốc < Nhánh phải

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

BinTree createNode(Data, BinTree = NULL, BinTree = NULL);
void clearTree(BinTree &);
void addNode(BinTree &, Data);
unsigned countLv2Node(BinTree);

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
        cout << "Cây nhị phân có " << countLv2Node(tree) << " nút bậc hai\n";
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

unsigned countLv2Node(BinTree tree) {
    if (tree) {
        return
            countLv2Node(tree->left) +
            countLv2Node(tree->right) +
            unsigned(tree->left && tree->right)
        ;
    }
    return 0;
}
