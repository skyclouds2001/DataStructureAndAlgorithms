class Solution {
public:
    int strStr(string haystack, string needle) {
        int hl = haystack.length(), nl = needle.length();

        int p = 0, hp = 0, np = 0;
        int ans = -1;

        while(p < hl) {
            hp = p;

            if (haystack[hp] == needle[np]) {
                while (hp < hl && np < nl && haystack[hp] == needle[np]) {
                    ++hp;
                    ++np;
                }

                if (np == nl) {
                    ans = p;
                    break;
                }

                np = 0;
            }

            ++p;
        }

        return ans;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        string h = haystack, n = needle;
        int hl = haystack.length(), nl = needle.length();

        vector<int> next(nl, 0);
        for (int i = 1, j = 0; i < nl; i++) {
            while (j > 0 && n[i] != n[j]) {
                j = next[j - 1];
            }
            if (n[i] == n[j]) {
                ++j;
            }
            next[i] = j;
        }

        int ans = -1;
        for (int i = 0, j = 0; i < hl; ++i) {
            while (j > 0 && h[i] != n[j]) {
                j = next[j - 1];
            }
            if (h[i] == n[j]) {
                ++j;
            }
            if (j == nl) {
                ans = i - nl + 1;
                break;
            }
        }

        return ans;
    }
};
