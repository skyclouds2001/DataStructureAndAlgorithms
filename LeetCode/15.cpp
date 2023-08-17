class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int len = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; ++i) {
            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int left = i  + 1;
            int right = len - 1;

            while (left < right) {
                if (nums[left] + nums[right] + nums[i] == 0) {
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    while (right > left && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    while (right > left && nums[left] == nums[left + 1]) {
                        ++left;
                    }

                    ++left;
                    --right;
                } else if (nums[left] + nums[right] + nums[i] < 0) {
                    ++left;
                } else if (nums[left] + nums[right] + nums[i] > 0) {
                    --right;
                }
            }
        }

        return ans;
    }
};
