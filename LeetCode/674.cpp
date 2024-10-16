class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const int size = nums.size();
        vector<int> dp(size, 1);
        int res = dp[0];
        for (int i = 1; i < size; ++i) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const int size = nums.size();
        int cnt = 1;
        int res = cnt;
        for (int i = 1; i < size; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                cnt = 1;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
