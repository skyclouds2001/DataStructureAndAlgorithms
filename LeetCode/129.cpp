class Solution {
    int calculate(vector<int>& v, TreeNode* node) {
        v.push_back(node -> val);

        int sum = 0;

        if (node -> left == nullptr && node -> right == nullptr) {
            for (auto c: v) {
                sum *= 10;
                sum += c;
            }
        }

        if (node -> left != nullptr) {
            sum += calculate(v, node -> left);
        }
        if (node -> right != nullptr) {
            sum += calculate(v, node -> right);
        }

        v.pop_back();

        return sum;
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int> list;

        return calculate(list, root);
    }
};
