#include <iostream>
#include <string>

using namespace std;

int n;
int dp[50];

int main(int argc, char const *argv[]) {
    cin >> n;

    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;

    return 0;
}
