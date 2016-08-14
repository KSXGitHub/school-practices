
#include <iostream>

using namespace std;

unsigned sumsqr(unsigned n) {
    return n ? n * n + sumsqr(n - 1) : 0;
}

int main() {
    unsigned n;
    cout << "n = ";
    cin >> n;
    cout << "S(n) = " << sumsqr(n) << endl;
    return 0;
}
