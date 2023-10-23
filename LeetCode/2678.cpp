class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;

        for (auto detail: details) {
          char c1 = detail[11];
          char c2 = detail[12];
          int age = (c1 - '0') * 10 + (c2 - '0');
          if (age > 60) {
            ++cnt;
          }
        }

        return cnt;
    }
};
