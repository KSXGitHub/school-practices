
#include <iostream>

using namespace std;

/* TYPES AND CLASSES */

typedef int Data;

struct Node {
    Data data;
    Node *next;
};

typedef Node *List;

/* FUNCTION PROTOTYPES */

int main();
void inputList(List &);
void printList(List);
Node *createNode(Data, Node * = NULL);
void pushFront(List &, Data);
void clearList(List &);

/* FUNCTION PROTOTYPES */

int main() {
    List list = NULL;
    cout << "(size, ...list): ";
    inputList(list);
    cout << "list -> reverse:";
    printList(list);
    clearList(list);
    return 0;
}

void inputList(List &list) {
    unsigned size;
    for (cin >> size; size; --size) {
        Data data;
        cin >> data;
        pushFront(list, data);
    }
}

void printList(List list) {
    for (Node *node = list; node; node = node->next) {
        cout << '\x20' << node->data;
    }
    cout << endl;
}

void pushFront(List &list, Data data) {
    Node *head = new Node();
    *head = {data, list};
    list = head;
}

void clearList(List &list) {
    Node *node = list;
    while (node) {
        Node *next = node->next;
        delete node;
        node = next;
    }
    list = NULL;
}
