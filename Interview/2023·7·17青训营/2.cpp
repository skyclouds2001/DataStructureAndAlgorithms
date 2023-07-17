class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        size_t len = nums.size();
        int sum = 0;
        int ans = 0;

        sum += nums.at(0);
        for (int i = 0; i < len; ++i) {
            if (sum < 0) {
                sum = nums.at(i);
            } else {
                sum += nums.at(i);
            }
            ans = std::max(ans, sum);
        }
        return ans;
    }
};
