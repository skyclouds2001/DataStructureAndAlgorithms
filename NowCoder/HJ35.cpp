#include <iostream>
#include <string>

using namespace std;

int N;
int mp[100 + 1][100 + 1];
int T;
int x, y, p;

int main(int argc, char const *argv[]) {
    cin >> N;
    T = N * (N + 1) / 2;

    x = 1;
    y = 1;
    p = 1;

    while (p <= T) {
        mp[x][y] = p;
        ++p;
        --x;
        ++y;
        if (x == 0) {
            x = y;
            y = 1;
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N - i + 1; ++j) {
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
