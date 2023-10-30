class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int size = citations.size();
        int left = 1, right = size;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (citations[size - mid] >= mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};
