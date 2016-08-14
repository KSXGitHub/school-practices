
#include <iostream>
#include <cstdlib>

using namespace std;

/* TYPES AND CLASSES */

typedef unsigned Data;
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
void xuatDanhSachDaoNguoc(List &);
void xoaNguyenTo(List &);

Node *createNode(Data, Node * = NULL);
void clearList(List &);
void addNode(List &, Data);
void reverseList(List &);
Data disposeNodeAfter(Node *);

bool isPrime(unsigned);

/* FUNCTION DEFINTIONS */

int main() {
    List danhsach = {NULL};
    system("chcp 65001");
    cout << "Nhập số lượng và các phần tử của Danh sách: ";
    nhap(danhsach);
    if (danhsach.head) {
        cout << "Danh sách đã nhập: ";
        xuat(danhsach);
        xuatDanhSachDaoNguoc(danhsach);
        xoaNguyenTo(danhsach);
        clearList(danhsach);
    } else {
        cout << "Các thao tác sau là vô nghĩa vì danh sách trống nên được bỏ qua,\nXin chào và hẹn gặp lại!\n";
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

void xuatDanhSachDaoNguoc(List &danhsach) {
    reverseList(danhsach);
    cout << "Danh sách đã đảo ngược: ";
    xuat(danhsach);
}

void xoaNguyenTo(List &danhsach) {

    // @begin: node tạm thời, liên kết với @head, dùng để tiện xóa @head
    // @prev: bắt đầu từ @begin, luôn đứng kề sau @current, dùng để xóa @current
    // @current: luôn đứng trước @prev, dùng để kiểm tra số nguyên tố
    Node begin = {0, danhsach.head};
    Node *prev = &begin, *current = danhsach.head;

    // Những số nguyên tố bị xóa sẽ được liệt kê
    cout << "Các số nguyên tố trong danh sách: ";

    // Vòng lặp: Tìm, xóa, liệt kê các số nguyên tố
    while (current) {
        Node *next = current->next;
        if (isPrime(current->data)) {
            cout << '\x20' << disposeNodeAfter(prev);
        } else {
            prev = current;
        }
        current = next;
    }

    cout << endl;
    danhsach.head = begin.next;

    cout << "Danh sách sau khi loại bỏ các số nguyên tố: ";
    xuat(danhsach);

}

Node *createNode(Data data, Node *next) {
    Node *node = new Node();
    *node = {data, next};
    return node;
}

void clearList(List &list) {
    Node *current = list.head;
    while (current) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    list.head = NULL;
}

void addNode(List &list, Data data) {
    list.head = createNode(data, list.head);
}

void reverseList(List &list) {

    // @begin: temporary buffer node
    // @last: limit of the outer loop
    Node begin = {0, list.head}, *last = NULL;

    // Outer loop:
    //  * Purpose: move every single elements to their corresponding position
    //  * Move: @last steps backward until it hits @head
    while (list.head != last) {

        // @back -> @middle -> @front: run through the list (in the inner loop) until @front hits @last
        Node *back = &begin, *middle = list.head, *front = middle->next;

        // inner loop: move n-th node to last-n-th position
        while (front != last) {

            // redirect links
            back->next = front;
            middle->next = front->next;
            front->next = middle;

            // step forward
            back = front;
            middle = back->next;
            front = middle->next;

        }

        // last steps backward
        last = middle;

    }

    // bring the head back
    list.head = begin.next;

}

Data disposeNodeAfter(Node *node) {
    Node *disposed = node->next;
    node->next = disposed->next;
    Data out = disposed->data;
    delete disposed;
    return out;
}

bool isPrime(unsigned prime) {
    if (prime < 2) {
        return false;
    }
    if (prime == 2) {
        return true;
    }
    if (prime & 1) {
        for (unsigned i = 3; i != prime; i += 2) {
            if (!(prime % i)) {
                return false;
            }
        }
        return true;
    }
    return false;
}
