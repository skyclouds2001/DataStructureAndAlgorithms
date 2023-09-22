class Solution {
public:
    /**
     * @param n int整型
     * @return int整型
     */
    int fun(int n) {
        string s = to_string(n);
        int ans = 0;

        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '0' || s[i] == '5') {
                break;
            } else {
                ++ans;
            }
        }

        return ans;
    }
};
