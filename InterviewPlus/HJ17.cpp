#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void resolve(string& s, int& x, int& y) {
    if (s.length() != 2 && s.length() != 3) {
        s.clear();
        return;
    }

    if (s[0] != 'A' && s[0] != 'S' && s[0] != 'W' && s[0] != 'D') {
        s.clear();
        return;
    }

    if (!isdigit(s[1])) {
        s.clear();
        return;
    }

    if (s.length() == 3 && !isdigit(s[2])) {
        s.clear();
        return;
    }

    char cmd = s[0];
    int pos = s[1] - '0';

    if (s.length() == 3) {
        pos *= 10;
        pos += s[2] - '0';
    }

    switch(cmd) {
        case 'A':
            x -= pos;
            break;
        case 'S':
            y -= pos;
            break;
        case 'W':
            y += pos;
            break;
        case 'D':
            x += pos;
            break;
    }

    s.clear();
}

int main() {
    int x = 0, y = 0;
    string str, s;
    cin >> str;

    for (char c: str) {
        if (c != ';') {
            s += c;
            continue;
        }

        resolve(s, x, y);
    }

    cout << x << ',' << y << endl;

    return 0;
}
