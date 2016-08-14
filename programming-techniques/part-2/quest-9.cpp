
#include <iostream>

using namespace std;

int main();
void input(int *&, unsigned &);
int find(int *, unsigned, int);

int main() {
    int *sequence, key;
    unsigned size;
    cout << "(size, ...sequence, key) = ";
    input(sequence, size);
    cin >> key;
    cout << "sequence.indexOf(key) = " << find(sequence, size, key) << endl;
    delete[] sequence;
    return 0;
}

void input(int *&sequence, unsigned &size) {
    cin >> size;
    sequence = new int[size];
    for (int *i = sequence, *e = i + size; i != e; ++i) {
        cin >> *i;
    }
}

int find(int *sequence, unsigned size, int key) {
    if (size) {
        int current = *sequence;
        if (key == current) {
            return 0;
        }
        if (key < current) {
            return -1;
        }
        int next = find(sequence + 1, size - 1, key);
        return next == -1 ? -1 : 1 + next;
    }
    return -1;
}
