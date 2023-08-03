class MyStack {
private:
    std::queue<int> queue;
    std::queue<int> cache;
public:
    MyStack() {}

    void push(int x) {
        queue.push(x);
    }

    int pop() {
        while (queue.size() > 1) {
            int v = queue.front();
            queue.pop();
            cache.push(v);
        }
        int val = queue.front();
        queue.pop();
        while (!cache.empty()) {
            int v = cache.front();
            cache.pop();
            queue.push(v);
        }
        return val;
    }

    int top() {
        return queue.back();
    }

    bool empty() {
        return queue.empty();
    }
};
