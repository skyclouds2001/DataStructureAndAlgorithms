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
