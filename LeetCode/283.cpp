class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int fast = 0; // 当前遍历位置
        int slow = 0; // 当前待赋值位置
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
