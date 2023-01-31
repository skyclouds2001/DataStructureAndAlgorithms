class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len);
        int start = 0, end = len - 1;
        int pos = len - 1;
        while (start <= end) {
            long long s = nums[start], e = nums[end];
            if (s * s > e * e) {
                ans[pos] = s * s;
                ++start;
            } else {
                ans[pos] = e * e;
                --end;
            }
            --pos;
        }
        return ans;
    }
};
