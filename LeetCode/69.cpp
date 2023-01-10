class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        if (x == 1) {
            return 1;
        }

        int l = 0, r = x;
        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if ((long long)mid * mid > x) {
                r = mid - 1;
            } else if ((long long)mid * mid < x) {
                res = mid;
                l = mid + 1;
            } else {
                res = mid;
                break;
            }
        }
        if (res == -1) {
            res = l;
        }
        return res;
    }
};
