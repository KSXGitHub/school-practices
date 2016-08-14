
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
Node *createNode(Data, Node * = NULL);
Queue createQueue();
void addNode(Queue &, Data);
Data disposeNode(Queue &, unsigned);
Data disposeHead(Queue &);
unsigned count(Queue);
void clearQueue(Queue &);

/* FUNCTION DEFINITIONS */

int main() {
    Queue queue = createQueue();
    unsigned n;
    system("chcp 65001");
    cout << "Nhập số lượng và các phần tử hàng đợi: ";
    nhap(queue);
    cout << "Số phần tử của hàng đợi: " << count(queue) << endl;
    cout << "Nội dung của hàng đợi: ";
    xuat(queue);
    cout << "Nhập n: ";
    cin >> n;
    cout << "Đã xóa một phần tử có giá trị bằng " << disposeNode(queue, n) << " khỏi hàng đợi\n";
    cout << "Nội dung của hàng đợi: ";
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

void xuat(Queue queue) {
    for (Node *node = queue.head; node; node = node->next) {
        cout << '\x20' << node->data;
    }
    cout << endl;
}

Node *createNode(Data data, Node *next) {
    Node *node = new Node;
    node->data = data;
    node->next = next;
    return node;
}

Queue createQueue() {
    Queue queue;
    queue.head = queue.tail = NULL;
    return queue;
}

void addNode(Queue &queue, Data data) {
    Node *newnode = createNode(data, NULL);
    if (queue.tail) {
        queue.tail->next = newnode;
    }
    queue.tail = newnode;
    if (!queue.head) {
        queue.head = newnode;
    }
}

Data disposeNode(Queue &queue, unsigned position) {
    if (position) {
        Node *prev = NULL, *current = queue.head;
        while (position) {
            prev = current;
            current = current->next;
            --position;
        }
        Data out = current->data;
        prev->next = current->next;
        if (current == queue.tail) {
            queue.head = prev;
        }
        delete current;
        return out;
    }
    return disposeHead(queue);
}

Data disposeHead(Queue &queue) {
    Node *node = queue.head;
    if (node) {
        Data out = node->data;
        queue.head = node->next;
        if (node == queue.tail) {
            queue.tail = NULL;
        }
        delete node;
        return out;
    }
    throw "Failed to dispose an empty queue";
}

unsigned count(Queue queue) {
    unsigned result = 0;
    for (Node *node = queue.head; node; node = node->next) {
        ++result;
    }
    return result;
}

void clearQueue(Queue &queue) {
    Node *current = queue.head, *next;
    while (current) {
        next = current->next;
        delete current;
        current = next;
    }
    queue.head = queue.tail = NULL;
}
