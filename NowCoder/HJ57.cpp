#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string num1, num2;
string total;

int main(int argc, char const *argv[]) {
    cin >> num1 >> num2;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int lmax = max(num1.length(), num2.length());
    int lmin = min(num1.length(), num2.length());
    int ap = 0;

    for(int i = 0; i < lmin; ++i) {
        int n1 = num1[i] - '0';
        int n2 = num2[i] - '0';
        int ni = n1 + n2 + ap;
        ap = ni / 10;
        ni %= 10;
        total += (char)(ni + '0');
    }

    if (num1.length() == num2.length()) {
        if (ap != 0) {
            total += (char)(ap + '0');
        }
    } else if (num1.length() == lmax) {
        for (int i = lmin; i < lmax; ++i) {
            int ni = (num1[i] - '0') + ap;
            ap = ni / 10;
            ni %= 10;
            total += (char)(ni + '0');
        }
    } else if (num2.length() == lmax) {
        for (int i = lmin; i < lmax; ++i) {
            int ni = (num2[i] - '0') + ap;
            ap = ni / 10;
            ni %= 10;
            total += (char)(ni + '0');
        }
    }

    reverse(total.begin(), total.end());

    cout << total << endl;

    return 0;
}
