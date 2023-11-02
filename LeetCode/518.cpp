class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);

        dp[0] = 1;

        for (auto coin: coins) {
            for (int k = coin; k <= amount; ++k) {
                dp[k] = dp[k] + dp[k - coin];
            }
        }

        return dp[amount];
    }
};
