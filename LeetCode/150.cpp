class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> nums;

        for(auto c: tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                long long n1 = nums.top();
                nums.pop();
                long long n2 = nums.top();
                nums.pop();

                long long ans = 0;

                if (c == "+") {
                    ans = n2 + n1;
                }
                if (c == "-") {
                    ans = n2 - n1;
                }
                if (c == "*") {
                    ans = n2 * n1;
                }
                if (c == "/") {
                    ans = n2 / n1;
                }

                nums.push(ans);
            } else {
                nums.push(stoll(c));
            }
        }

        return nums.top();
    }
};
