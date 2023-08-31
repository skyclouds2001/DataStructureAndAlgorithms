class Solution {
private:
    void traversal(Node* p, vector<int>& v) {
        if (p == nullptr) {
            return;
        }

        v.push_back(p -> val);
        for (auto p: p -> children) {
            traversal(p, v);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> v;

        traversal(root, v);

        return v;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> s;
        vector<int> v;

        if (root == nullptr) {
            return v;
        }

        s.push(root);
        while(!s.empty()) {
            Node* node = s.top();
            s.pop();

            v.push_back(node -> val);
            for (auto it = (node -> children).rbegin(); it != (node -> children).rend(); ++it) {
                if (*it != nullptr) {
                    s.push(*it);
                }
            }
        }

        return v;
    }
};
