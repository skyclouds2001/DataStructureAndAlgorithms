class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int flag = 0;
        int x = 0, y = 0;
        for (int i = 0; i < n * n; ++i) {
            ans[x][y] = i;

            switch (flag % 4) {
                case 0:
                    if (y + 1 >= n || ans[x][y + 1] != 0) {
                        ++flag;
                        ++x;
                    } else {
                        ++y;
                    }
                    break;
                case 1:
                    if (x + 1 >= n || ans[x + 1][y] != 0) {
                        ++flag;
                        --y;
                    } else {
                        ++x;
                    }
                    break;
                case 2:
                    if (y - 1 < 0 || ans[x][y - 1] != 0) {
                        ++flag;
                        --x;
                    } else {
                        --y;
                    }
                    break;
                case 3:
                    if (x - 1 < 0 || ans[x - 1][y] != 0) {
                        ++flag;
                        ++y;
                    } else {
                        --x;
                    }
                    break;
            }
        }

        return ans;
    }
};
