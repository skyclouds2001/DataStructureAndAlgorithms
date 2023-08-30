class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int fast = 0;
        int slow = 0;
        while (fast < len) {
            if (nums[fast] != val) {
                if (fast != slow) {
                    nums[slow] = nums[fast];
                }
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
