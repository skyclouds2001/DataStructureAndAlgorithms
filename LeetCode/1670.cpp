#include "deque"

using namespace std;

class FrontMiddleBackQueue {
private:
    deque<int> frontQueue;
    deque<int> backQueue;
public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        this->frontQueue.push_front(val);
    }

    void pushMiddle(int val) {
        while (this->frontQueue.size() - this->backQueue.size() > 0) {
            int val = this->frontQueue.back();
            this->frontQueue.pop_back();
            this->backQueue.push_front(val);
        }
        while (this->backQueue.size() - this->frontQueue.size() > 1) {
            int val = this->backQueue.front();
            this->backQueue.pop_front();
            this->frontQueue.push_back(val);
        }

        this->frontQueue.push_back(val);
    }

    void pushBack(int val) {
        this->backQueue.push_back(val);
    }

    int popFront() {
        if (this->frontQueue.empty() && this->backQueue.empty()) {
            return -1;
        } else if (this->frontQueue.empty()) {
            int val = this->backQueue.front();
            this->backQueue.pop_front();
            return val;
        } else {
            int val = this->frontQueue.front();
            this->frontQueue.pop_front();
            return val;
        }
    }

    int popMiddle() {
        if (this->frontQueue.empty() && this->backQueue.empty()) {
            return -1;
        }

        while (this->frontQueue.size() - this->backQueue.size() > 1) {
            int val = this->frontQueue.back();
            this->frontQueue.pop_back();
            this->backQueue.push_front(val);
        }
        while (this->backQueue.size() - this->frontQueue.size() > 1) {
            int val = this->backQueue.front();
            this->backQueue.pop_front();
            this->frontQueue.push_back(val);
        }

        if (this->frontQueue.size() == this->backQueue.size() + 1) {
            int val = this->frontQueue.back();
            this->frontQueue.pop_back();
            return val;
        } else if (this->frontQueue.size() + 1 == this->backQueue.size()) {
            int val = this->backQueue.front();
            this->backQueue.pop_front();
            return val;
        } else {
            int val = this->frontQueue.back();
            this->frontQueue.pop_back();
            return val;
        }

    }

    int popBack() {
        if (this->frontQueue.empty() && this->backQueue.empty()) {
            return -1;
        } else if (this->backQueue.empty()) {
            int val = this->frontQueue.back();
            this->frontQueue.pop_back();
            return val;
        } else {
            int val = this->backQueue.back();
            this->backQueue.pop_back();
            return val;
        }
    }
};
