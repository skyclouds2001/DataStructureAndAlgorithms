class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        const int size = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto str: strs) {
            int c0 = 0, c1 = 0;
            for (auto s: str) {
                switch (s) {
                    case '0':
                        ++c0;
                        break;
                    case '1':
                        ++c1;
                        break;
                }
            }

            for (int i = m; i >= c0; --i) {
                for (int j = n; j >= c1; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - c0][j - c1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
