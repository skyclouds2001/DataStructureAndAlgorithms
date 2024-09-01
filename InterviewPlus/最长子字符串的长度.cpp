#include <iostream>
#include <string>

using namespace std;

int main() {
    int n = 0;
    string s;

    cin >> s;
    for (auto c : s) {
        if (c == 'o') ++n;
    }
    if (n % 2 == 0) {
        cout << s.length() << endl;
    } else {
        cout << s.length() - 1 << endl;
    }

    return 0;
}
