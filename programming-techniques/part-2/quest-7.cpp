
#include <iostream>

using namespace std;

unsigned combinations(unsigned n, unsigned r) {
    return r ? n * combinations(n - 1, r - 1) : 1;
}

int main() {
    unsigned n, r;
    cout << "(n, r) = ";
    cin >> n >> r;
    cout << "nCr = " << combinations(n, r) << endl;
    return 0;
}
