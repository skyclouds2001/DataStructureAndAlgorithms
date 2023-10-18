class Solution {
public:
    int numTrees(int n) {
        int dp[19 + 1] = {0};

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[i - j] * dp[j - 1];
            }
        }

        return dp[n];
    }
};
