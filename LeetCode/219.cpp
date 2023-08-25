#include "vector"
#include "unordered_set"

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int size = nums.size();

        unordered_set<int> set;
        int begin = 0;
        int end = 0;

        for (; end < k && end < size; ++end) {
            if (set.contains(nums[end])) {
                return true;
            } else {
                set.insert(nums[end]);
            }
        }

        for (; end < size; ++begin, ++end) {
            if (set.contains(nums[end])) {
                return true;
            } else {
                set.insert(nums[end]);
            }
            set.erase(nums[begin]);
        }

        return false;
    }
};
