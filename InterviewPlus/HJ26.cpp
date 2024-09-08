#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    string ss;
    for (char c: s) {
        if (isalpha(c)) {
            ss += c;
        }
    }
    const int ss_size = ss.length();

    for (int i = 0; i < ss_size; ++i) {
        for (int j = 0; j < ss_size - i - 1; ++j) {
            if (tolower(ss[j]) > tolower(ss[j + 1])) {
                swap(ss[j], ss[j + 1]);
            }
        }
    }

    const int s_size = s.length();
    int i = 0, j = 0;
    while(i < s_size && j < ss_size) {
        if (isalpha(s[i])) {
            s[i] = ss[j];
            ++i;
            ++j;
        } else {
            ++i;
        }
    }

    cout << s << endl;

    return 0;
}
