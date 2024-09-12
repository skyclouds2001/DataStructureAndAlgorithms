#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int first, last;
int pos;

int main(int argc, char const *argv[]) {
    cin >> n;
    cin >> s;

    if (n <= 4) {
        first = 1;
        last = n;
        pos = 1;

        for (const auto& c: s) {
            switch (c) {
                case 'U':
                    if (pos == 1) {
                        pos = n;
                        break;
                    }
                    pos = pos - 1;
                    break;
                case 'D':
                    if (pos == n) {
                        pos = 1;
                        break;
                    }
                    pos = pos + 1;
                    break;
            }
        }
    } else {
        first = 1;
        last = 4;
        pos = 1;

        for (const auto& c: s) {
            switch (c) {
                case 'U':
                    if (pos == 1) {
                        if (first == 1) {
                            pos = 4;
                            first = n - 3;
                            last = n;
                        } else {
                            first = first - 1;
                            last = last - 1;
                        }
                        break;
                    }
                    pos = pos - 1;
                    break;
                case 'D':
                    if (pos == 4) {
                        if (last == n) {
                            pos = 1;
                            first = 1;
                            last = 4;
                        } else {
                            first = first + 1;
                            last = last + 1;
                        }
                        break;
                    }
                    pos = pos + 1;
                    break;
            }
        }
    }

    for (int k = first; k <= last; ++k) {
        cout << k << ' ';
    }
    cout << endl;
    cout << (first + pos - 1) << endl;;

    return 0;
}
