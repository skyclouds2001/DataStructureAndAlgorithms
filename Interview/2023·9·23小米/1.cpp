#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:
    long long matrixSum(int n, vector<vector<int>> operations) {
        long long res = 0;
        int type, index, val;
        const int size = operations.size();

        unordered_set<int> columns;
        unordered_set<int> rows;

        for (int k = 1; k <= size; ++k) {
            auto operation = operations[size - k];

            type = operation[0];
            index = operation[1];
            val = operation[2];

            switch (type) {
                case 0:
                    if (rows.count(index) == 0) {
                        res += (n - columns.size()) * val;

                        rows.insert(index);
                    }
                    break;
                case 1:
                    if (columns.count(index) == 0) {
                        res += (n - rows.size()) * val;

                        columns.insert(index);
                    }
                    break;
            }
        }

        return res;
    }
};

int main() {
    long long res;

    int n;
    cin >> n;

    int operations_rows = 0;
    int operations_cols = 0;
    cin >> operations_rows >> operations_cols;
    vector<vector<int>> operations(operations_rows);
    for(int operations_i=0; operations_i<operations_rows; operations_i++) {
        for(int operations_j=0; operations_j<operations_cols; operations_j++) {
            int operations_tmp;
            cin >> operations_tmp;
            operations[operations_i].push_back(operations_tmp);
        }
    }

    Solution *s = new Solution();
    res = s->matrixSum(n, operations);
    cout << res;

    return 0;
}
