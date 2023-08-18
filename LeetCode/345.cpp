class Solution {
private:
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool isVowel(const char c) {
        return vowels.count(c) > 0;
    }
public:
    string reverseVowels(string s) {
        const int len = s.length();

        int start = 0;
        int end = len - 1;

        while (start < end) {
            while(start < len && !isVowel(s[start])) {
                ++start;
            }
            while(end > 0 && !isVowel(s[end])) {
                --end;
            }

            if (start > end) {
                break;
            }

            swap(s[start], s[end]);

            ++start;
            --end;
        }

        return s;
    }
};
