#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main(int argc, char const *argv[]) {
    string str;
    getline(cin, str);

    int cnt = 0;

    for (char c: str) {
        if (isupper(c)) {
            ++cnt;
        }
    }

    cout << cnt << endl;

    return 0;
}
