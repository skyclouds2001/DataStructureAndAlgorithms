class Solution {
private:
    stack<int> stack;
public:
    int calPoints(vector<string>& operations) {
        for (string& s: operations) {
            if (s.compare("+") == 0) {
                int s1 = this->stack.top();
                this->stack.pop();
                int s2 = this->stack.top();
                this->stack.push(s1);

                this->stack.push(s1 + s2);
            } else if (s.compare("D") == 0) {
                int s = this->stack.top();

                this->stack.push(2 * s);
            } else if (s.compare("C") == 0) {
                int s = this->stack.top();

                this->stack.pop();
            } else {
                int i = stoi(s);

                this->stack.push(i);
            }
        }

        int score = 0;
        while (!this->stack.empty()) {
            score += this->stack.top();
            this->stack.pop();
        }

        return score;
    }
};
