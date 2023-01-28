class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int fast = 1; // 当前遍历位置
        int slow = 1; // 当前待赋值位置
        while (fast < len) {
            if (nums[fast] != nums[fast - 1]) {
                if (slow != fast) {
                    nums[slow] = nums[fast];
                }
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
