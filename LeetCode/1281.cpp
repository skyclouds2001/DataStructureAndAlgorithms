class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int mul = 1;
        while (n) {
            int v = n % 10;
            sum += v;
            mul *= v;
            n /= 10;
        }
        return mul - sum;
    }
};
