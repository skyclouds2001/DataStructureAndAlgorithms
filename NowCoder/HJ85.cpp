#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

bool dp[350 + 1][350 + 1];

int main(int argc, char const *argv[]) {
    string str;
    cin >> str;
    int size = str.length();

    if (size == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (size == 2) {
        if (str[0] == str[1]) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }

    int max_len = 1;

    for (int i = 1; i <= size; i++) {
        dp[i][i] = true;
    }

    for (int len = 2; len <= size; len++) {
        for (int i = 1; i <= size - len + 1; i++) {
            int j = i + len - 1;

            if (str[i - 1] == str[j - 1]) {
                if (j - i < 3) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            } else {
                dp[i][j] = false;
            }

            if (dp[i][j]) {
                max_len = max(max_len, j - i + 1);
            }
        }
    }

    cout << max_len << endl;

    return 0;
}
