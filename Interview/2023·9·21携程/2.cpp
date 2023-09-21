#include "iostream"
#include "string"

using namespace std;

int q;
string s;
string t;

int main() {
    cin >> q;

    for (int k = 0; k < q; ++k) {
        cin >> s;
        cin >> t;

        bool flag = true;

        int sl = s.length();
        int tl = t.length();

        for (int i = 0; i < tl; ++i) {
            for (int j = i + 1; j < tl; ++j) {
                if (t[i] != t[j]) {
                    if (s[i] == s[j]) {
                        flag = false;
                        goto END;
                    }
                }
            }
        }

        END:

        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
