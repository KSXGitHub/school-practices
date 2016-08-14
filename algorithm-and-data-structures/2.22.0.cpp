
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
    Node first;
    Node last;
};

/* FUNCTION PROTOTYPES */

int main();
void nhap(List &);
void xuat(List &);
void xuatDanhSachDaoNguoc(List &);
void xoaNguyenTo(List &);

void initList(List &);
Node *createNode(Data, Node *);
bool isEmpty(List &);
void clearList(List &);
void addNode(List &, Data);
void disposeAfter(Node *);
void reverseList(List &);

bool isPrime(unsigned);

/* FUNCTION DEFINITIONS */

int main() {
    List danhsach;
    initList(danhsach);
    cout << "Nhập số lượng và các phần tử của Danh sách: ";
    nhap(danhsach);
    if (isEmpty(danhsach)) {
        cout << "Danh sách trống, mọi tác vụ về sau là vô nghĩa nên được bỏ qua.\nHẹn gặp lại!\n";
    } else {
        reverseList(danhsach);
        cout << "Danh sách đã nhâp: ";
        xuat(danhsach);
        xuatDanhSachDaoNguoc(danhsach);
        clearList(danhsach);
    }
    return 0;
}

void nhap(List &danhsach) {
    unsigned soluong;
    for (cin >> soluong; soluong; --soluong) {
        Data phantu;
        cin >> phantu;
        addNode(danhsach, phantu);
    }
}

void xuat(List &danhsach) {
    for (Node *node = danhsach.first.next; node != &danhsach.last; node = node->next) {
        cout << '\x20' << node->data;
    }
    cout << endl;
}

void xuatDanhSachDaoNguoc(List &danhsach) {
    cout << "Danh sách sau khi đã đảo ngược: ";
    reverseList(danhsach);
    xuat(danhsach);
}

void initList(List &list) {
    list.first.next = &list.last;
}

Node *createNode(Data data, Node *next) {
    Node *node = new Node();
    *node = {data, next};
    return node;
}

bool isEmpty(List &list) {
    return list.first.next == &list.last;
}

void clearList(List &list) {
    Node *node = list.first.next;
    while (node != &list.last) {
        Node *next = node->next;
        delete node;
        node = next;
    }
    initList(list);
}

void addNode(List &list, Data data) {
    list.first.next = createNode(data, list.first.next);
}

void reverseList(List &list) {
    Node *last = &list.last;
    while (list.first.next != last) {
        Node *back = &list.first, *middle = list.first.next, *front = middle->next;
        while (front != last) {
            back->next = front;
            middle->next = front->next;
            front->next = middle;
            back = front;
            middle = back->next;
            front = middle->next;
        }
        last = middle;
    }
}
