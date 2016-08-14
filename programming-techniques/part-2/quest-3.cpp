
#include <iostream>

using namespace std;

unsigned fibonacci(unsigned n) {
    switch (n) {
        case 0:
            return 0;
        case 1:
            return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    unsigned n;
    cout << "n = ";
    cin >> n;
    cout << "range(0, n).map(fibonacci):";
    for (unsigned i = 0; i != n; ++i) {
        cout << ' ' << fibonacci(i);
    }
    return 0;
}
