#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int m_nKey;
    ListNode *m_pNext;
};

int n;

int val;
ListNode *pos;

ListNode *head;

int k;

ListNode *pre, *aft;

int main(int argc, char const *argv[]) {
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> val;
            if (head == nullptr) {
                head = new ListNode();
                pos = head;
                pos -> m_nKey = val;
                pos -> m_pNext = nullptr;
            } else {
                pos -> m_pNext = new ListNode();
                pos = pos -> m_pNext;
                pos -> m_nKey = val;
                pos -> m_pNext = nullptr;
            }
        }
        cin >> k;

        pre = head;
        for (int i = 0; i < k; ++i) {
            pre = pre -> m_pNext;
        }
        aft = head;
        while(pre != nullptr) {
            pre = pre -> m_pNext;
            aft = aft -> m_pNext;
        }
        cout << aft -> m_nKey << endl;
    }

    return 0;
}
