#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class Solution {
public:
    long long minimumFlips(string s) {
        const int size = s.size();
        long long ans = 0;

        // 4 - 2 - 2 || 0011 -> 1111 = 2
        // 5 - 2 - 2 || 01010
        // 6 - 3 - 3 || 010101 -3> 101101 -2> 011101 -1> 111101 -2> 111110 -1> 111111 = 9

        for (int k = size / 2; k > 0; --k) {
            while (s[k] == s[k - 1]) {
                --k;
            }
            ans += k;
        }

        for (int k = size / 2; k < size - 1; ++k) {
            while(s[k] == s[k + 1]) {
                ++k;
            }
            ans += size - k - 1;
        }

        return ans;
    }
};

int main() {
    long long res;

    string str;
    getline(cin, str);
    Solution *s = new Solution();
    res = s->minimumFlips(str);
    cout << res;

    return 0;
}
