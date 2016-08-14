
// Lưu ý:
//  * Chương trình này sử dụng Tiếng Việt có dấu (UTF-8), nên chạy chương trình trên console hỗ trợ UTF-8
//   - Nếu dùng CMD (%windir%\system32\cmd.exe), nhập lệnh `chcp 65001` trước khi chạy chương trình

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
void addList(List &, List);
void addList(List &, Node *);
List merge(List, List);

/* FUNCTION DEFINITIONS */

int main() {
    List A = {NULL}, B = {NULL};
    system("chcp 65001");
    cout << "Nhập số lượng và các phần tử của Danh sách A: ";
    nhap(A);
    cout << "Nhập số lượng và các phần tử của Danh sách B: ";
    nhap(B);
    if (A.head && B.head) {
        cout << "Danh sách A: ";
        xuat(A);
        cout << "Danh sách B: ";
        xuat(B);
        List C = merge(A, B);
        cout << "Danh sách A + B: ";
        xuat(C);
        clearList(A);
        clearList(B);
        clearList(C);
    } else {
        cout << "Có ít nhất một danh sách trống rỗng nên không có việc gì để làm.\nChào thân ái và quyết thắng!\n";
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
        if (data < list.head->data) {
            Node *newnode = createNode(data, list.head);
            list.head = newnode;
        } else if (data != list.head->data) {
            Node *prev = list.head, *current = prev->next;
            while (current) {
                if (data < current->data) {
                    prev->next = createNode(data, current);
                    return;
                }
                if (data == current->data) {
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

void addList(List &target, List addend) {
    addList(target, addend.head);
}

void addList(List &target, Node *addend) {
    for (Node *node = addend; node; node = node->next) {
        addNode(target, node->data);
    }
}

List merge(List lsta, List lstb) {
    List lsto = {NULL};
    addList(lsto, lsta);
    addList(lsto, lstb);
    return lsto;
}
