class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                ++count;
            }
        }

        s.resize(s.size() + 2 * count);

        for (int i = s.size() - 1, j = s.size() - 2 * count - 1; i != j;) {
            if (s[j] == ' ') {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 3;
                j -= 1;
            } else {
                s[i] = s[j];
                --i;
                --j;
            }
        }

        return s;
    }
};
