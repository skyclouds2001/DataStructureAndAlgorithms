#include "iostream"
#include "string"
#include "set"

using namespace std;

int main() {
    string s;
    cin >> s;

    set<char> set;
    for (auto c: s) {
        set.insert(c);
    }

    for (auto c: set) {
        cout << c;
    }

    return 0;
}
