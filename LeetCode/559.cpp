class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int d = 0;
        for (auto c: root -> children) {
            d = max(d, maxDepth(c));
        }

        return d + 1;
    }
};
