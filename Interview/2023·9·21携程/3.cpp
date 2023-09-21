#include "cstdio"
#include "iostream"

using namespace std;

int n;
int m;
int rect[500][500];
int total;

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &(rect[i][j]));
        }
    }

    total = ((m + 1) * m / 2) * ((n + 1) * n / 2);

    cout << total << endl;

    return 0;
}
