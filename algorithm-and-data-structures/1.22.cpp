
#include <iostream>
#include <cstdlib>

using namespace std;

/* TYPES AND CLASSES */

typedef int Data;

struct Node {
    Data data;
    Node *next;
};

struct Queue {
    Node *head, *tail;
};

/* FUNCTION PROTOTYPES */

int main();
void nhap(Queue &);
void xuat(Queue);
Node *createNode(Data = Data());
Queue createQueue();
void addNode(Queue &, Data);
Data disposeNode(Queue &, unsigned);
unsigned count(Queue);
void clearQueue(Queue &);

/* FUNCTION DEFINITIONS */

int main() {
    Queue queue = createQueue(queue);
    unsigned n;
    cout << "Nhap so luong va cac phan tu cua hang doi: ";
    nhap(queue);
    cout << "So phan tu cua hang doi: " << count(queue) << endl;
    cout << "Noi dung hang doi: ";
    xuat(queue);
    cout << "Nhap n: ";
    cin >> n;
    cout << "Phan tu thu n cua hang doi: " << disposeNode(queue, n) << endl;
    cout << "Hang doi sau khi xoa phan tu thu n: ";
    xuat(queue);
    clearQueue(queue);
    return 0;
}

void nhap(Queue &queue) {
    unsigned count;
    for (cin >> count; count; --count) {
        Data data;
        cin >> data;
        addNode(queue, data);
    }
}

Node *createNode(Data data = Data()) {
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

Queue createQueue() {
    Queue queue;
    queue.head = queue.tail = NULL;
}

void clearQueue(Queue &queue) {
    Node *current = queue.head, *next;
    while (current) {
        next = current->next;
        delete current;
        current = next;
    }
}
