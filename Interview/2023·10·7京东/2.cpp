#include "iostream"
#include "string"

using namespace std;

int n;
int m;
string s[100000 + 1];
int a[100000 + 1];
bool dy[100000 + 1];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] >> a[i];
    }

    int u, v;
    char c1, c2;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> c1 >> c2;

        // one die
        if (dy[u] || dy[v]) {
            continue;
        }

        // both private
        if (c1 == 'N' && c2 == 'N') {
            continue;
        }

        // same role
        if (s[u] == s[v]) {
            continue;
        }

        // only monster public and monster better than human
        if (c1 == 'Y' && c2 == 'N' && s[v] == "human" && a[u] > a[v] ||
                c1 == 'N' && c2 == 'Y' && s[u] == "human" && a[v] > a[u]) {
            continue;
        }

        if (a[u] == a[v]) {
            dy[u] = true;
            dy[v] = true;
        } else if (a[u] > a[v]) {
            dy[v] = true;
        } else if (a[u] < a[v]) {
            dy[u] = true;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << (not dy[i] ? 'Y' : 'N');
    }
    cout << endl;

    return 0;
}
