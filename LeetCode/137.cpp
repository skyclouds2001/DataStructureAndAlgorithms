class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32];
        for (int i = 0; i < 32; ++i) {
            bits[i] = 0;
        }

        for (auto num: nums) {
            for (int i = 0; i < 32; ++i) {
                bits[i] += (num >> i) & 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if (bits[i] % 3 == 1) {
                ans += (1 << i);
            }
        }

        return ans;
    }
};
