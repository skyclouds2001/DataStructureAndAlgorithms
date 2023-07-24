class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1) return false;

        std::stack<char> stack;
        for (auto c: s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.empty()) return false;

                char cc = stack.top();
                stack.pop();
                if (!(c == ')' && cc == '(' || c == ']' && cc == '[' || c == '}' && cc == '{')) {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};
