class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> result;

        for (auto c: nums1) {
            if (map.find(c) != map.end()) {
                ++map[c];
            } else {
                map[c] = 1;
            }
        }

        for (auto c: nums2) {
            if (map.find(c) != map.end() && map[c] > 0) {
                --map[c];
                result.push_back(c);
            }
        }

        return result;
    }
};
