#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' && (i == 0 || s[i - 1] == '0') && (i == n - 1 || s[i + 1] == '0')) {
            ++cnt;
            ++i;
        }
    }

    cout << cnt << endl;

    return 0;
}
