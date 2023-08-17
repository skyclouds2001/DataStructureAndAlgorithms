#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int len = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; ++i) {
            if (nums[i] > target && nums[i] >= 0) {
                break;
            }

            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            for (int j = i + 1; j < len; ++j) {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                    break;
                }

                if (j > i + 1 && nums[j - 1] == nums[j]) {
                    continue;
                }

                int left = j + 1;
                int right = len - 1;

                while (left < right) {
                    if ((long long)nums[i] + nums[j] + nums[left] + nums[right] == target) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            --right;
                        }

                        ++left;
                        --right;
                    } else if ((long long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        ++left;
                    } else if ((long long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        --right;
                    }
                }
            }
        }

        return res;
    }
};
