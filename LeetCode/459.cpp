class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);
        return ss.find(s) != string::npos;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        vector<int> next(len, 0);
        for (int i = 1, j = 0; i < len; i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
        return next[len - 1] > 0 && len % (len - next[len - 1]) == 0;
    }
};
