class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int size = nums.size();
        const int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum || (sum + abs(target)) % 2 == 1) {
            return 0;
        }

        vector<vector<int>> dp(size + 1, vector<int>(sum * 2 + 1, 0));

        dp[0][sum] = 1;

        for (int i = 1; i <= size; ++i) {
            for (int k = 0; k <= 2 * sum; ++k) {
                if (k + nums[i - 1] <= 2 * sum && k + nums[i - 1] >= 0) {
                    dp[i][k] += dp[i - 1][k + nums[i - 1]];
                }
                if (k - nums[i - 1] <= 2 * sum && k - nums[i - 1] >= 0) {
                    dp[i][k] += dp[i - 1][k - nums[i - 1]];
                }
            }
        }

        return dp[size][target + sum];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int size = nums.size();
        const int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum || (sum + abs(target)) % 2 == 1) {
            return 0;
        }

        int dg = (sum + target) / 2;

        vector<int> dp(dg + 1, 0);

        for (int i = 0; i < size; ++i) {
            for (int j = dg; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[dg];
    }
};
