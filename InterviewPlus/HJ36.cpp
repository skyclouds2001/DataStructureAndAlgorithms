#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
    string raw_key, key, raw, secret;
    set<char> set;

    cin >> raw_key;
    cin >> raw;

    for (auto c: raw_key) {
        if (set.count(c) == 0) {
            set.insert(c);
            key += c;
        }
    }

    for (int i = (int)('a'); i <= (int)('z'); ++i) {
        if (set.count(i) == 0) {
            key += (char)(i);
        }
    }

    for (auto c: raw) {
      secret += key[c - 'a'];
    }

    cout << secret << endl;

    return 0;
}
