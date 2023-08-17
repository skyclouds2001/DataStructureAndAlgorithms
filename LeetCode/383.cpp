class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};

        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        for (auto c: magazine) {
            ++count[c - 'a'];
        }

        for (auto c: ransomNote) {
            --count[c - 'a'];
            if (count[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
