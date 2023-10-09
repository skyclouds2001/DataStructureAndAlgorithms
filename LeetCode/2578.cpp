class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        const int len = s.length();
        sort(s.begin(), s.end());

        string s1, s2;
        for (int i = 0; i < len; ++i) {
            switch (i % 2) {
                case 0:
                    s1 += s[i];
                    break;
                case 1:
                    s2 += s[i];
                    break;
            }
        }

        return stoi(s1) + stoi(s2);
    }
};
