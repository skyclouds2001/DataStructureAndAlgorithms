#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string str;
    cin >> str;
    string ans;

    for (auto ch: str) {
        if (ch >= 'a' && ch <= 'z') {
            char c = ch;
            switch (c) {
                case 'a':
                case 'b':
                case 'c':
                    c = '2';
                    break;
                case 'd':
                case 'e':
                case 'f':
                    c = '3';
                    break;
                case 'g':
                case 'h':
                case 'i':
                    c = '4';
                    break;
                case 'j':
                case 'k':
                case 'l':
                    c = '5';
                    break;
                case 'm':
                case 'n':
                case 'o':
                    c = '6';
                    break;
                case 'p':
                case 'q':
                case 'r':
                case 's':
                    c = '7';
                    break;
                case 't':
                case 'u':
                case 'v':
                    c = '8';
                    break;
                case 'w':
                case 'x':
                case 'y':
                case 'z':
                    c = '9';
                    break;
            }
            ans += c;
        } else if (ch >= 'A' && ch <= 'Z') {
            char c = (ch - 'A' + 1) % 26 + 'a';
            ans += c;
        } else {
            ans += ch;
        }
    }

    cout << ans << endl;

    return 0;
}
