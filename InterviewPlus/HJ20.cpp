#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        bool flag = true;

        if (s.length() < 8) {
            flag = false;
        }

        {
            bool lower = false, upper = false, number = false, other = false;
            for (auto c: s) {
                if (c >= 'a' && c <= 'z') {
                    lower = true;
                } else if (c >= 'A' && c <= 'Z') {
                    upper = true;
                } else if (c >= '0' && c <= '9') {
                    number = true;
                } else {
                    other = true;
                }
            }
            int cnt  = 0;
            if (lower) {
                ++cnt;
            }
            if (upper) {
                ++cnt;
            }
            if (number) {
                ++cnt;
            }
            if (other) {
                ++cnt;
            }
            if (cnt < 3) {
                flag = false;
            }
        }

        {
            const int len = s.length();
            for (int i = 0; i < len - 1 && flag; ++i) {
                for (int j = i + 1; j < len && flag; ++j) {
                    if (s[i] == s[j]) {
                        int x = i, y = j;
                        while (s[x] == s[y]) {
                            ++x;
                            ++y;
                            if (x - i > 2 || y - j > 2) {
                                flag = false;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (flag) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }
    }

    return 0;
}
