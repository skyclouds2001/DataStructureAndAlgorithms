class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int size = s.size();
        unordered_set<char> set;
        int len = 0;

        for (int begin = 0, end = 0; begin < size; ++begin) {
            if (begin != 0) {
                set.erase(s[begin - 1]);
            }

            while (end < size && set.count(s[end]) == 0) {
                set.insert(s[end]);
                ++end;
            }

            len = max(len, end - begin);
        }

        return len;
    }
};
