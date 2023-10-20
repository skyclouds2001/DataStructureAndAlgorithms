class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        const int size = stones.size();
        const int sum = accumulate(stones.begin(), stones.end(), 0);
        const int target = sum / 2;

        vector<int> dp(target + 1, 0);
        for (int i = 0; i < size; ++i) {
            for (int j = target; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - dp[target] - dp[target];
    }
};
