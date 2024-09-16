#include <iostream>
#include <string>

using namespace std;

string s;
int n;

int rn;
string rs;

int rnmax;
string rsmax;

int main(int argc, char const *argv[]) {
    cin >> s;
    cin >> n;

    for (int k = 0; k < n; ++k) {
        if (s[k] == 'C' || s[k] == 'G') {
            ++rn;
        }
        rs += s[k];
    }

    rnmax = rn;
    rsmax = rs;

    for (int k = n; k < s.length(); ++k) {
        if (rs[0] == 'C' || rs[0] == 'G') {
            --rn;
        }
        if (s[k] == 'C' || s[k] == 'G') {
            ++rn;
        }
        rs = rs.erase(0, 1);
        rs += s[k];
        if (rn > rnmax) {
            rnmax = rn;
            rsmax = rs;
        }
    }

    cout << rsmax << endl;

    return 0;
}
