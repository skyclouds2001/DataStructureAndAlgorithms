#include <iostream>
#include <string>
#include <map>

using namespace std;

string str;
map<char, int> mp;

int main(int argc, char const *argv[]) {
    cin >> str;
    for (auto c: str) {
        ++mp[c];
    }
    for (auto c: str) {
        if (mp[c] == 1) {
            cout << c << endl;

            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
