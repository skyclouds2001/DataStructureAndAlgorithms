class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        const int len = s.length();

        for (int i = 0; i < 2 * len - 1; ++i) {
            int l = i / 2;
            int r = i / 2 + i % 2;
            while(l >= 0 && r < len && s[l] == s[r]) {
                ++count;

                --l;
                ++r;
            }
        }

        return count;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(s.length() + 1, false));

        for (int i = s.length(); i >= 1; i--) {
            for (int j = i; j <= s.length(); j++) {
                if (s[i - 1] == s[j - 1] && (j - i == 0 || j - i == 1 || dp[i + 1][j - 1])) {
                    ++cnt;
                    dp[i][j] = true;
                }
            }
        }

        return cnt;
    }
};
