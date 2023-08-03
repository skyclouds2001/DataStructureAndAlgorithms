class MyQueue {
private:
    std::stack<int> stackIn;
    std::stack<int> stackOut;
public:
    MyQueue() {}

    void push(int x) {
        stackIn.push(x);
    }

    int pop() {
        int val = peek();
        stackOut.pop();
        return val;
    }

    int peek() {
        if (stackOut.empty()) {
            while(!stackIn.empty()) {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        return stackOut.top();
    }

    bool empty() {
        return stackIn.empty() && stackOut.empty();
    }
};
