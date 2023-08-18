class Solution {
public:
    string reverseWords(string s) {
        int len, fast, slow;

        len = s.length();
        fast = 0;
        slow = 0;
        while (fast < len) {
            if (s[fast] != ' ') {
                if (slow != 0) {
                    s[slow] = ' ';
                    ++slow;
                }

                while (fast < len && s[fast] != ' ') {
                    s[slow] = s[fast];
                    ++slow;
                    ++fast;
                }
            }
            ++fast;
        }
        s.resize(slow);

        len = s.length();
        fast = len - 1;
        slow = 0;
        while (fast > slow) {
            swap(s[slow], s[fast]);
            --fast;
            ++slow;
        }

        fast = 0;
        slow = 0;
        while (fast < len) {
            while (fast < len && s[fast] != ' ') {
                ++fast;
            }

            int l = slow, r = fast - 1;
            while (l < r) {
                swap(s[l], s[r]);
                ++l;
                --r;
            }

            ++fast;
            slow = fast;
        }

        return s;
    }
};
