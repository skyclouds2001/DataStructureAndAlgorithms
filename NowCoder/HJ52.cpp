#include <iostream>
#include <string>

using namespace std;

string sa, sb;
int sla, slb;
int dp[1000 + 1][1000 + 1];

int main(int argc, char const *argv[]) {
    cin >> sa;
    sla = sa.length();
    cin >> sb;
    slb = sb.length();

    for (int i = 0; i <= sla; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= slb; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= sla; i++) {
        for (int j = 1; j <= slb; j++) {
            dp[i][j] = min(dp[i - 1][j - 1] + (sa[i - 1] == sb[j - 1] ? 0 : 1), min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
    }

    cout << dp[sla][slb] << endl;

    return 0;
}
