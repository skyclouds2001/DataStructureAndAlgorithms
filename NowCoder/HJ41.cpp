#include <iostream>
#include <string>
#include <set>

using namespace std;

int n;
int m[10];
int x[10];

int cnt;
set<int> cases;

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int k = 0; k < n; ++k) {
        cin >> m[k];
    }
    for (int k = 0; k < n; ++k) {
        cin >> x[k];
    }

    cases.insert(0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            for (auto c: set(cases)) {
                cases.insert(c + m[i]);
            }
        }
    }

    cout << cases.size() << endl;

    return 0;
}
