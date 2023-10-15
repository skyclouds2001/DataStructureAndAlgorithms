class Solution {
private:
    int dp[1000 + 1];
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int size = cost.size();

        if (size == 0 || size == 1) {
            return 0;
        }

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= size; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[size];
    }
};
