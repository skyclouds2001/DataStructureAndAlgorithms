class Solution {
public:
    string removeDuplicates(string s) {
        std::stack<char> stack;

        for (auto c: s) {
            if (stack.empty() || stack.top() != c) {
                stack.push(c);
            } else {
                stack.pop();
            };
        }

        string res = "";
        while (!stack.empty()) {
            res.push_back(stack.top());
            stack.pop();
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};
