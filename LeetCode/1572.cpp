class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int size = mat.size();
        int sum = 0;

        for (int i = 0; i < size; ++i) {
            sum += mat[i][i];
            if (size - i - 1 != i) sum += mat[size - i - 1][i];
        }

        return sum;
    }
};
