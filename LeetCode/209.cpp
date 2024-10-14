class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int len = INT_MAX;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= target) {
                int l = i - j + 1;
                len = len > l ? l : len;
                sum -= nums[j];
                ++j;
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
