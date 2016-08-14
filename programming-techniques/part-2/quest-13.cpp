
#include <iostream>

using namespace std;

void printbin(unsigned dec) {
    if (dec) {
        printbin(dec >> 1);
        cout << (dec & 1);
    } else {
        cout << 0;
    }
}

int main() {
    unsigned n;
    cout << "dec: ";
    cin >> n;
    cout << "bin: ";
    printbin(n);
    cout << endl;
    return 0;
}
