class Solution {
private:
    const long long MOD = 10e9 + 7;
    queue<TreeNode*> q;
    int getTreeDeepestNodeCount(TreeNode* node) {
        q.push(node);
        int total;

        while (true) {
            const int size = q.size();

            for (int i = 0; i < size; ++i) {
                auto p = q.front();
                q.pop();

                if (p -> left != nullptr) {
                    q.push(p -> left);
                }
                if (p -> right != nullptr) {
                    q.push(p -> right);
                }
            }

            if (q.empty()) {
                total = size;
                break;
            }
        }

        return total;
    }
    long long calc(int n) {
        return n == 0 ? 1 : n * calc(n - 1) % MOD;
    }
public:
    /**
     * @param trees TreeNode类vector
     * @return int整型
     */
    int cntOfMethods(vector<TreeNode*>& trees) {
        vector<long long> v;
        long long total = 1;
        long long count = 0;

        for (auto tree: trees) {
            long long c = getTreeDeepestNodeCount(tree);

            v.push_back(c);

            total *= c * 2;
            total %= MOD;
        }

        long long an = calc(v.size() - 1);

        for (auto c: v) {
            count += total / (c * 2) * an;
            count %= MOD;
        }

        return count;
    }
};
