
#include <iostream>

using namespace std;

const unsigned MAXSTRSZ = 255;

int main();
char *eostr(char *);
bool symetry(char *, char *);

int main() {
    char str[MAXSTRSZ];
    cout << "Nhập một chuỗi: ";
    cin.getline(str, MAXSTRSZ, '\n');
    cout << "Chuỗi " << (symetry(str, eostr(str) - 1) ? "" : "không ") << "đối xứng\n";
    return 0;
}

char *eostr(char *str) {
    for ( ; *str; ++str);
    return str;
}

bool symetry(char *begin, char *end) {
    return begin == end ||
        begin == end - 1 ||
        (*begin == *end && symetry(begin + 1, end - 1));
}
