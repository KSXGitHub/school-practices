
#include <iostream>

using namespace std;

unsigned power(double a, unsigned n) {
    return n ? a * power(a, n - 1) : 1;
}

int main() {
    double a;
    unsigned n;
    cout << "(a, n) = ";
    cin >> a >> n;
    cout << "a\u207F = " << power(a, n) << endl;
    return 0;
}
