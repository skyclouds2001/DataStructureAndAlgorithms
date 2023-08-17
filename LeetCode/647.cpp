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
