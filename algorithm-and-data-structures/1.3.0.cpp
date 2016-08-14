
#include <iostream>

using namespace std;

/* TYPES AND CLASSES */

typedef int Data;

struct Node {
    Data data;
    Node *next;
};

struct List {
    Node *head, *tail;
};

/* FUNCTION PROTOTYPES */

int main();
void inputList(List &);
void printList(List);
void initList(List &);
void pushBack(List &, Data);
void clearList(List &);

/* FUNCTION DEFINITIONS */

int main() {
    List list;
    cout << "(size, ...list): ";
    inputList(list);
    cout << "list:";
    printList(list);
    clearList(list);
    return 0;
}

void inputList(List &list) {
    unsigned size;
    initList(list);
    for (cin >> size; size; --size) {
        Data data;
        cin >> data;
        pushBack(list, data);
    }
}

void printList(List list) {
    for (Node *node = list.head; node != list.tail; node = node->next) {
        cout << '\x20' << node->data;
    }
    cout << endl;
}

void initList(List &list) {
    list.tail = new Node();
    list.head = list.tail;
}

void pushBack(List &list, Data data) {
    list.tail->data = data;
    Node *next = new Node();
    list.tail->next = next;
    list.tail = next;
}

void clearList(List &list) {
    Node *node = list.head;
    while (node != list.tail) {
        Node *next = node->next;
        delete node;
        node = next;
    }
    delete list.tail;
    initList(list);
}
