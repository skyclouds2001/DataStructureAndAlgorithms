class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;

        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            const int size = q.size();

            for (int i = 0; i < size; ++i) {
                Node* n = q.front();
                q.pop();

                if (i == size - 1) {
                    n -> next = nullptr;
                } else {
                    n -> next = q.front();
                }

                if (n -> left != nullptr) {
                    q.push(n -> left);
                }
                if (n -> right != nullptr) {
                    q.push(n -> right);
                }
            }
        }

        return root;
    }
};
