class Solution {
public:
    int countDigits(int num) {
        int val = num;
        int cnt = 0;

        while (val > 0) {
            if (num % (val % 10) == 0) {
                ++cnt;
            }
            val /= 10;
        }

        return cnt;
    }
};
