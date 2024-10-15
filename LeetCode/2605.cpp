class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            swap(nums1, nums2);
        }

        unordered_set<int> set(nums1.begin(), nums1.end());

        int f = INT_MAX;

        for (auto n: nums2) {
            if (set.contains(n)) {
                f = min(f, n);
            }
        }

        int min1 = *min_element(nums1.begin(), nums1.end());
        int min2 = *min_element(nums2.begin(), nums2.end());

        return f != INT_MAX ? f : min1 > min2 ? min2 * 10 + min1 : min1 * 10 + min2;
    }
};
