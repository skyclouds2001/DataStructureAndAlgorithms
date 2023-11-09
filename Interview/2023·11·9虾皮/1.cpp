class Solution {
public:
    vector<int> moveZero(vector<int>& array) {
        int size = array.size();
        vector<int> arr;
        int cnt = 0;

        for (int k = 0; k < size; ++k) {
            if (array[k] != 0) {
                arr.push_back(array[k]);
            } else {
                ++cnt;
            }
        }

        for (int k = 0; k < cnt; ++k) {
            arr.push_back(0);
        }

        return arr;
    }
};
