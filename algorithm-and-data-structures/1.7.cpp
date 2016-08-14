
#include <iostream>
#include <cstdlib>

using namespace std;

/* TYPES AND CLASSES */

typedef int Data;
struct Node;
struct List;

struct Node {
    Data data;
    Node *next;
};

struct List {
    Node *head;
};

/* FUNCTION PROTOTYPES */

int main();
void nhap(List &);
void xuat(List);

Node *createNode(Data, Node * = NULL);
void clearList(List &);
void addNode(List &, Data);

/* FUNCTION DEFINITIONS */

int main() {
    List list = {NULL};
    system("chcp 65001");
    cout << "Nhập số lượng và các phần tử: ";
    nhap(list);
    if (list.head) {
        cout << "Danh sách đã nhập (đã sắp xếp): ";
        xuat(list);
        clearList(list);
    } else {
        cout << "Danh sách rỗng, không có việc gì để làm.\nChào thân ái!\n";
    }
}

void nhap(List &list) {
    unsigned soluong;
    for (cin >> soluong; soluong; --soluong) {
        Data phantu;
        cin >> phantu;
        addNode(list, phantu);
    }
}

void xuat(List list) {
    for (Node *node = list.head; node; node = node->next) {
        cout << '\x20' << node->data;
    }
    cout << endl;
}

Node *createNode(Data data, Node *next) {
    Node *node = new Node();
    *node = {data, next};
    return node;
}

void clearList(List &list) {
    Node *node = list.head;
    while (node) {
        Node *next = node->next;
        delete node;
        node = next;
    }
    list = {NULL};
}

void addNode(List &list, Data data) {
    if (list.head) {
        if (data <= list.head->data) {
            Node *newnode = createNode(data, list.head);
            list.head = newnode;
        } else {
            Node *prev = list.head, *current = prev->next;
            while (current) {
                if (data <= current->data) {
                    prev->next = createNode(data, current);
                    return;
                }
                prev = current;
                current = current->next;
            }
            prev->next = createNode(data);
        }
    } else {
        list.head = createNode(data);
    }
}
