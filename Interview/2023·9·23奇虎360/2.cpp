#include "iostream"
#include "string"

using namespace std;

int T;
string s;

int main() {
    cin >> T;

    for (int k = 0; k < T; ++k) {
        cin >> s;
        const int size = s.length();
        bool flag = true;

        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
