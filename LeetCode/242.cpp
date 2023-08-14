class Solution {
public:
    bool isAnagram(string s, string t) {
        int cc[26] = {0};

        for (auto c: s) {
            ++cc[c - 'a'];
        }

        for (auto c: t) {
            --cc[c - 'a'];
        }

        bool flag = true;
        for (int i = 0; i < 26; ++i) {
            if (cc[i] != 0) {
                flag = false;
            }
        }

        return flag;
    }
};
