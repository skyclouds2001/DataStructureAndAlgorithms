class Solution {
private:
    int calc(int n) {
        return pow(2, n);
    }
public:
    /**
     * @param str string字符串 由小写字母组成,字符串长度不大于1000000
     * @return int整型
     */
    int getCount(string str) {
        const int len = str.length();
        int total = 0;

        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (str[i] == str[j]) {
                    total += calc(j - i - 1);
                }
            }
        }

        return total;
    }
};
