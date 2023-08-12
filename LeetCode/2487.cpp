#include "stack"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    stack<ListNode*> stack;
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* p = head;

        while (p != nullptr) {
            while (!stack.empty() && stack.top() -> val < p -> val) {
                stack.pop();
            }
            stack.push(p);
            p = p -> next;
        }

        ListNode* pp = nullptr;
        while (!stack.empty()) {
            p = stack.top();
            stack.pop();
            p -> next = pp;
            pp = p;
        }

        return p;
    }
};
