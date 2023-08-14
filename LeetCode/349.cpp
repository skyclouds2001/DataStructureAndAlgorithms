class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;

        set<int> n(nums1.begin(), nums1.end());

        for (auto c: nums2) {
            if (n.find(c) != n.end()) {
                result.insert(c);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
