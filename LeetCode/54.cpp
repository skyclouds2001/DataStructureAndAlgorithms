class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.at(0).size();
        int m = matrix.size();

        vector<vector<bool>> visited(m, vector<bool>(n));

        vector<int> res;

        int flag = 0;
        int x = 0, y = 0;
        for (int i = 0; i < n * m; ++i) {
            res.push_back(matrix[x][y]);
            visited[x][y] = true;
            cout << x << ' ' << y << ' ' << matrix[x][y] << endl;
            switch (flag % 4) {
                case 0:
                    if (y >= n - 1 || visited[x][y + 1]) {
                        ++flag;
                        ++x;
                    } else {
                        ++y;
                    }
                    break;
                case 1:
                    if (x >= m - 1 || visited[x + 1][y]) {
                        ++flag;
                        --y;
                    } else {
                        ++x;
                    }
                    break;
                case 2:
                    if (y <= 0 || visited[x][y - 1]) {
                        ++flag;
                        --x;
                    } else {
                        --y;
                    }
                    break;
                case 3:
                    if (x <= 0 || visited[x - 1][y]) {
                        ++flag;
                        ++y;
                    } else {
                        --x;
                    }
                    break;
            }
        }

        return res;
    }
};
