#include <iostream>
#include <string>

using namespace std;

int n, m;

int mp[10][10];

int main(int argc, char const *argv[]) {
    cin >> n >> m;

    mp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        mp[i][0] = mp[i - 1][0];
    }

    for (int j = 1; j <= m; ++j) {
        mp[0][j] = mp[0][j - 1];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            mp[i][j] = mp[i - 1][j] + mp[i][j - 1];
        }
    }

    cout << mp[n][m] << endl;

    return 0;
}
