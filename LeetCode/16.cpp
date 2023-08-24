class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int len = nums.size();

        int ans = 1e7;

        auto save = [&](int cur) {
            if (abs(cur - target) < abs( ans - target)) {
                ans = cur;
            }
        };

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int left = i + 1;
            int right = len - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                save(sum);

                if (sum == target) {
                    goto EXIT;
                } else if (sum > target) {
                    int r = right;
                    while (left < r && nums[r] == nums[right]) {
                        --r;
                    }
                    right = r;
                } else if (sum < target) {
                    int l = left;
                    while (l < right && nums[l] == nums[left]) {
                        ++l;
                    }
                    left = l;
                }
            }
        }

        EXIT:

        return ans;
    }
};
