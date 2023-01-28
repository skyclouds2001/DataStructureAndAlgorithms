class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int fast = 0, slow = 0;
        while (fast < len) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
