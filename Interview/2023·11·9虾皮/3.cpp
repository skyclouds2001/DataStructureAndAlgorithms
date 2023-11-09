class Solution {
public:
    int findReverseOrderNum(vector<int>& arr) {
        const int size = arr.size();

        vector<int> b_min(size, 0);
        vector<int> e_max(size, 0);

        b_min[0] = arr[0];
        e_max[size - 1] = arr[size - 1];

        for (int i = 1; i < size; ++i) {
            b_min[i] = min(b_min[i - 1], arr[i]);
            e_max[size - i - 1] = max(e_max[size - i], arr[size - i - 1]);
        }

        for (int i = 1; i < size - 1; ++i) {
            if (b_min[i] == e_max[i]) {
                return i;
            }
        }

        return -1;
    }
};
