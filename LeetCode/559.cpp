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

class Solution {
    int result = 0;

    void getDepth(Node* node, int depth) {
        result = max(result, depth);

        for (auto c: node -> children) {
            if (c != nullptr) {
                ++depth;
                getDepth(c, depth);
                --depth;
            }
        }
    }
public:
    int maxDepth(Node* root) {
        if (root != nullptr) {
            getDepth(root, 1);
        }

        return result;
    }
};
