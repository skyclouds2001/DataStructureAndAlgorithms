class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        int len = nums.size();
        int l, r, mid;

        // left part
        l = 0;
        r = len;
        while (l < r) {
            mid = l + (r - l) / 2;
            cout << l << " " << r << " " << mid << endl;
            if (nums[mid] > target) {
                r = mid;
            }
            if (nums[mid] == target) {
                r = mid;
                start = mid;
            }
            if (nums[mid] < target) {
                l = mid + 1;
            }
        }
        if (len != 0 && nums[mid] == target) {
            start = mid;
        }

        // right part
        l = 0;
        r = len;
        while (l < r) {
            mid = l + (r - l) / 2;
            cout << l << " " << r << " " << mid << endl;
            if (nums[mid] < target) {
                l = mid + 1;
            }
            if (nums[mid] == target) {
                l = mid + 1;
                end = mid;
            }
            if (nums[mid] > target) {
                r = mid;
            }
        }
        if (len != 0 && nums[mid] == target) {
            end = mid;
        }

        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};
