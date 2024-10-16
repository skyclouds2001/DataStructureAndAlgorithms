class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int size = nums.size();
        vector<int> dp(size, 1);
        int res = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
