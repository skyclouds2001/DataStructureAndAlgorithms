class Solution {
public:
    vector<int> postorder(Node* root) {
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
            for (auto it = (node -> children).begin(); it != (node -> children).end(); ++it) {
                if (*it != nullptr) {
                    s.push(*it);
                }
            }
        }

        reverse(v.begin(), v.end());

        return v;
    }
};
