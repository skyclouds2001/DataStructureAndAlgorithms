#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
    string str;
    cin >> str;
    set<char> set;

    for (char c: str) {
        set.insert(c);
    }

    cout << set.size() << endl;

    return 0;
}
