class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      if (x == 0) return true;

      std::string s = std::to_string(x);

      for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
          return false;
        }
      }

      return true;
    }
};
