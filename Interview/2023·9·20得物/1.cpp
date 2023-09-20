#include "iostream"
#include "string"
#include "cctype"

using namespace std;

int get(char c) {
    int v = 0;

    switch (c) {
        case 'C':
            v = 12;
            break;
        case 'H':
            v = 1;
            break;
        case 'O':
            v = 16;
            break;
        case 'N':
            v = 14;
            break;
    }

    return v;
}

int main() {
    string s;
    cin >> s;

    int ans = 0;

    int v = 0;
    char a = 0;
    for (auto c: s) {
        if (isalpha(c)) {
            if (a != 0) {
                ans += get(a) * (v == 0 ? 1 : v);
            }

            v = 0;
            a = c;
        }
        if (isdigit(c)) {
            v *= 10;
            v += c - '0';
        }
    }

    if (a != 0) {
        ans += get(a) * (v == 0 ? 1 : v);
    }

    cout << ans << endl;

    return 0;
}
