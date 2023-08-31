class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        queue<Node*> q;

        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            int size = q.size();
            vector<int> vv;

            for (int i = 0; i < size; ++i) {
                Node* p = q.front();
                q.pop();

                vv.push_back(p -> val);

                for (auto p: p -> children) {
                    if (p != nullptr) {
                        q.push(p);
                    }
                }
            }

            v.push_back(vv);
        }

        return v;
    }
};
