class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }

        int m = money;
        int c = children;

        m -= children * 1;

        int cnt = min(m / 7, children);

        m -= cnt * 7;
        c -= cnt;

        if (c == 0 && m > 0) {
            cnt -= 1;
        } else if (c == 1 && m == 3) {
            cnt -= 1;
        } else {
            cnt;
        }

        return cnt;
    }
};
