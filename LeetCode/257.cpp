class Solution {
    vector<TreeNode*> vec;
    vector<string> res;
    void find(TreeNode* node) {
        if (node -> left == nullptr && node -> right == nullptr) {
            const int size = vec.size();
            string s;

            for (int i = 0; i < size; ++i) {
                s += to_string(vec[i] -> val);
                s += "->";
            }

            s += to_string(node -> val);

            res.push_back(s);
        }
        if (node -> left != nullptr) {
            vec.push_back(node);
            find(node -> left);
            vec.pop_back();
        }
        if (node -> right != nullptr) {
            vec.push_back(node);
            find(node -> right);
            vec.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        find(root);

        return res;
    }
};
