class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();  // 9
        int group = len / (2 * k) + 1;  // 3
        for (int i = 0; i < group; ++i) {
            int gs = (2 * i) * k;  // 0 4 8
            int ge = (2 * i + 1) * k - 1 < len ? (2 * i + 1) * k - 1: len - 1;  // 1 5 9->8
            for (int a = gs, b = ge; a < b; ++a, --b) {
                swap(s[a], s[b]);
            }
        }
        return s;
    }
};
