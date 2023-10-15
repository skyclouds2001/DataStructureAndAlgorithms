class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for (auto num: nums) {
            sum ^= num;
        }

        int test = (sum == INT_MIN) ? sum : sum & (-sum);

        vector<int> ans;
        int ans1 = 0, ans2 = 0;
        for (auto num: nums) {
            if (num & test) {
                ans1 ^= num;
            } else {
                ans2 ^= num;
            }
        }
        ans.push_back(ans1);
        ans.push_back(ans2);

        return ans;
    }
};
