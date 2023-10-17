class Solution {
public:
    int uniquePaths(int m, int n) {
        int map[m + 1][n + 1];

        for (int i = 0; i <= m; ++i) {
            map[i][0] = 0;
        }
        for (int i = 0; i <= n; ++i) {
            map[0][i] = 0;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                map[i][j] = i == 1 && j == 1 ? 1 : map[i - 1][j] + map[i][j - 1];
            }
        }

        return map[m][n];
    }
};
