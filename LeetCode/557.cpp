class Solution {
public:
    string reverseWords(string s) {
        const int len = s.length();

        int l = 0, r = 0;

        while (r < len) {
            while(l < len && s[l] == ' ') {
                ++l;
            }
            r = l;

            while(r < len && s[r] != ' ') {
                ++r;
            }

            for (int b = l, e = r - 1; b < e; ++b, --e) {
                swap(s[b], s[e]);
            }

            l = r;
        }

        return s;
    }
};
