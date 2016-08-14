
#include <iostream>

using namespace std;

unsigned factorial(unsigned n) {
    return n ? n * factorial(n - 1) : 1;
}

int main() {
    unsigned n;
    cout << "n = ";
    cin >> n;
    cout << "n! = " << factorial(n) << endl;
    return 0;
}
