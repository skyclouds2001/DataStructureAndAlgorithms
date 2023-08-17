#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;

        unordered_map<int, int> map;
        for (auto a: nums1) {
            for (auto b: nums2) {
                ++map[a + b];
            }
        }

        for (auto c: nums3) {
            for (auto d: nums4) {
                if (map.find(-(c + d)) != map.end()) {
                    count += map[-(c + d)];
                }
            }
        }

        return count;
    }
};
