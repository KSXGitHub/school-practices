
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

Node *createNode(Data = Data());
Queue createQueue();
void clearQueue(Queue &);

/* FUNCTION DEFINITIONS */

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
