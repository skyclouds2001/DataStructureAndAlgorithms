class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        int group = len / (2 * k) + 1;
        for (int i = 0; i < group; ++i) {
            int gs = (2 * i) * k;
            int ge = (2 * i + 1) * k - 1 < len ? (2 * i + 1) * k - 1: len - 1;
            for (int a = gs, b = ge; a < b; ++a, --b) {
                swap(s[a], s[b]);
            }
        }
        return s;
    }
};
