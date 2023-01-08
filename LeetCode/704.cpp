class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;

        for (int l = 0, r = nums.size() - 1; l <= r; ) {
            int mid = (l + r) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                res = mid;
                break;
            }
        }

        return res;
    }
};
