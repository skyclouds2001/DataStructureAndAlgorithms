class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int size = heights.size();

        int ma = 0;
        for (int i = 0; i < size; ++i) {
            if (abs(heights[i]) > ma) {
                ma = abs(heights[i]);
            }
        }

        return ma;
    }
};
