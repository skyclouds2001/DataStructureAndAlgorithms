#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    string str;
    cin >> str;

    string res;
    bool flag = false;

    for (char c: str) {
        if (isdigit(c)) {
            if (!flag) {
                flag = true;
                res += '*';
            }
            res += c;
        } else {
            if (flag) {
                flag = false;
                res += '*';
            }
            res += c;
        }
    }
    if (flag) {
        flag = false;
        res += '*';
    }

    cout << res << endl;

    return 0;
}
