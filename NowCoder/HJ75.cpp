#include <iostream>
#include <string>

using namespace std;

string str1, str2;
int slen1, slen2;
int dp[150 + 1][150 + 1];
int maxlen;

int main(int argc, char const *argv[]) {
    cin >> str1 >> str2;
    slen1 = str1.length();
    slen2 = str2.length();

    for (int i = 1; i <= slen1; ++i) {
        for (int j = 1; j <= slen2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxlen = max(maxlen, dp[i][j]);
            }
        }
    }

    cout << maxlen << endl;

    return 0;
}
