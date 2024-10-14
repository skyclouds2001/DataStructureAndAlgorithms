class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));

        for (int i = len; i >= 1; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j <= len; j++) {
                if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        int ans = dp[1][len];
        return ans;
    }
};
