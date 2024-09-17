#include <iostream>
#include <string>

using namespace std;

int main() {
    int x = 0, y = 0, cnt = 0;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'X') {
            ++x;
        }
        if (s[i] == 'Y') {
            ++y;
        }
        if (x == y) {
            x = 0;
            y = 0;
            ++cnt;
        }
    }

    cout << cnt << endl;

    return 0;
}
