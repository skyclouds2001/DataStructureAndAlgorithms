class Solution {
private:
    int calculate(int n) {
        int t = n;
        int res = 0;

        while(t > 0) {
            res += pow(t % 10, 2);
            t /= 10;
        }

        return res;
    }
public:
    bool isHappy(int n) {
        int t = n;
        unordered_set<int> set;

        while (true) {
            t = calculate(t);
            if (t == 1) {
                return true;
            }
            if (set.contains(t)) {
                return false;
            }
            set.insert(t);
        }
    }
};
