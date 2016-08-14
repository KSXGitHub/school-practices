
#include <iostream>

using namespace std;

unsigned gcd(unsigned a, unsigned b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    unsigned a, b;
    cout << "(a, b) = ";
    cin >> a >> b;
    cout << "gcd(a, b) = " << gcd(a, b) << endl;
    return 0;
}
