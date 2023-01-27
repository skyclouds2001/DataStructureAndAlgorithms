class Solution {
public:
    bool isPerfectSquare(int num) {
        bool flag = false;
        if (num == 1 || num == 4) {
            flag = true;
        } else {
            int l = 1;
            int r = num / 2;
            int mid;
            while (l < r) {
                mid = (l + r) / 2;
                if ((long long)mid * mid < num) {
                    l = mid + 1;
                } else if ((long long)mid * mid > num) {
                    r = mid;
                } else {
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }
};
