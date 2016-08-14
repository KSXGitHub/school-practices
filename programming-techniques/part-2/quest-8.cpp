
#include <iostream>

using namespace std;

int main();
void input1fv(float *&, unsigned &);
float min1fv(float *, unsigned);
float min2f(float, float);

int main() {
    float *sequence;
    unsigned size;
    cout << "(size, ...sequence) = ";
    input1fv(sequence, size);
    if (size) {
        cout << "min(sequence) = " << min1fv(sequence, size) << endl;
    } else {
        cout << "size == 0 is invalid\n";
    }
    delete[] sequence;
    return 0;
}

void input1fv(float *&sequence, unsigned &size) {
    cin >> size;
    sequence = new float[size];
    for (unsigned i = 0; i != size; ++i) {
        cin >> sequence[i];
    }
}

float min1fv(float *sequence, unsigned size) {
    float min = *sequence;
    return size == 1
        ? min
        : min2f(min, min1fv(sequence + 1, size - 1))
    ;
}

float min2f(float a, float b) {
    return a < b ? a : b;
}
