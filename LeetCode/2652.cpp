class Solution {
private:
    int calculate(int q, int n) {
        return (q + q * n) * n / 2;
    }
public:
    int sumOfMultiples(int n) {
        int sum = 0;

        sum += calculate(3, n / 3);
        sum += calculate(5, n / 5);
        sum += calculate(7, n / 7);
        sum -= calculate(15, n / (3 * 5));
        sum -= calculate(21, n / (3 * 7));
        sum -= calculate(35, n / (5 * 7));
        sum += calculate(105, n / (3 * 5 * 7));

        return sum;
    }
};
