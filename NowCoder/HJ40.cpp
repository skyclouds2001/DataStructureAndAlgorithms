#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int alpha = 0, blank = 0, digit = 0, other = 0;

    for (char c: s) {
        if (isalpha(c)) {
            alpha++;
        } else if (isblank(c)) {
            blank++;
        } else if (isdigit(c)) {
            digit++;
        } else {
            other++;
        }
    }

    cout << alpha << endl << blank << endl << digit << endl << other << endl;

    return 0;
}
