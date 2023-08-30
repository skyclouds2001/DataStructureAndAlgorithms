class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int fast = 0;
        int slow = 0;
        while (fast < len) {
            if (nums[fast] != 0) {
                if (fast != slow) {
                    nums[slow] = nums[fast];
                }
                ++slow;
            }
            ++fast;
        }
        while (slow < len) {
            nums[slow] = 0;
            ++slow;
        }
    }
};
