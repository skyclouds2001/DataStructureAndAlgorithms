class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int slen = s.length();
        int f1 = 0, s1 = 0; // f-字符串当前遍历位置 s-字符串赋值位置
        char ss[300] = {'\0'};
        strcpy(ss, s.c_str());
        char sss[300] = {'\0'};
        while (f1 < slen) {
            if (ss[f1] == '#') {
                if (s1 != 0) {
                    --s1;
                    sss[s1] = '\0';
                }
            } else {
                sss[s1] = ss[f1];
                ++s1;
            }
            ++f1;
        }
        int tlen = t.length();
        int f2 = 0, s2 = 0; // f-字符串当前遍历位置 s-字符串赋值位置
        char tt[300] = {'\0'};
        strcpy(tt, t.c_str());
        char ttt[300] = {'\0'};
        while (f2 < tlen) {
            if (tt[f2] == '#') {
                if (s2 != 0) {
                    --s2;
                    ttt[s2] = '\0';
                }
            } else {
                ttt[s2] = tt[f2];
                ++s2;
            }
            ++f2;
        }
        return strcmp(sss, ttt) == 0;
    }
};
