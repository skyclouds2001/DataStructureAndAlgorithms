class MyLinkedList {
public:
    MyLinkedList() {
        this -> head = new ListNode(0);
        this -> size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= this -> size) {
            return -1;
        } else {
            ListNode* p = this -> head -> next;
            for (int i = 0; i < index; ++i) {
                p = p -> next;
            }
            return p -> val;
        }
    }
    
    void addAtHead(int val) {
        ListNode* p = new ListNode(val); 
        p -> next = this -> head -> next;
        this -> head -> next = p;
        this -> size += 1;
    }
    
    void addAtTail(int val) {
        ListNode* p = this -> head;
        while (p -> next != NULL) {
            p = p -> next;
        }
        p -> next = new ListNode(val);
        this -> size += 1;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > this -> size) {
            return;
        } else if (index == this -> size) {
            this -> addAtTail(val);
        } else {
            ListNode* p = this -> head;
            for (int i = 0; i < index; ++i) {
                p = p -> next;
            }
            ListNode* q = new ListNode(val);
            q -> next = p -> next;
            p -> next = q;
            this -> size += 1;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= this -> size) {
            return;
        } else {
            ListNode* p = this -> head;
            for (int i = 0; i < index; ++i) {
                p = p -> next;
            }
            p -> next = p -> next -> next;
            this -> size -= 1;
        }
    }

private:
    struct ListNode {
        ListNode* next;
        int val;
        ListNode(int val): val(val), next(NULL) {}
    };
    ListNode* head;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
 