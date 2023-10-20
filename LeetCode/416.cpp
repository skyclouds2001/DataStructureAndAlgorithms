class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int size = nums.size();

        if (size == 1) {
            return false;
        }

        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
        }

        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;

        bool dp[target + 1];
        for (int k = 0; k <= target; ++k) {
            dp[k] = false;
        }
        dp[0] = true;
        for (int i = 0; i < size; ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] |= dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};
