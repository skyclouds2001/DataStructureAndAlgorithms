#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> line;
    int n, t;
    cin >> n;
    for (int k = 0; k < n; ++k) {
        cin >> t;
        line.push_back(t);
    }

    vector<int> asc(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (line[j] < line[i]) {
                asc[i] = max(asc[i], asc[j] + 1);
            }
        }
    }

    vector<int> desc(n, 1);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (line[i] > line[j]) {
                desc[i] = max(desc[i], desc[j] + 1);
            }
        }
    }

    int res = 0;
    for (int k = 0; k < n; ++k) {
        res = max(res, asc[k] + desc[k] - 1);
    }
    cout << (n - res) << endl;

    return 0;
}
