class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        const int size = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                ++mp[nums[i] * nums[j]];
            }
        }

        for (auto &[k, v]: mp) {
            ans += v * (v - 1) * 4;
        }

        return ans;
    }
};
