
// Lưu ý:
//  * Đây là một file *.hpp, không phải *.cpp nên không thể dịch tạo file *.exe để chạy được

#include <iostream>

using namespace std;

/* TYPES AND CLASSES */

typedef int Data;
struct Node;
struct Stack;

struct Node {
    Data data;
    Node *next;
};

struct Stack {
    Node *head;
};

/* FUNCTION PROTOTYPES */

Node *createNode(Data, Node * = NULL);
void push(Stack &, Data);
bool pop(Stack &, Data &);
void clear(Stack &);

/* FUNCTION DEFINITIONS */

Node *createNode(Data data, Node *next) {
    Node *node = new Node();
    *node = {data, next};
    return node;
}

void push(Stack &stack, Data data) {
    stack.head = createNode(data, stack.head);
}

bool pop(Stack &stack, Data &data) {
    if (stack.head) {
        Node *node = stack.head;
        data = node->data;
        stack.head = node->next;
        delete node;
        return true;
    }
    return false;
}

void clear(Stack &stack) {
    Node *node = stack.head;
    while (node) {
        Node *next = node->next;
        delete node;
        node = next;
    }
}
