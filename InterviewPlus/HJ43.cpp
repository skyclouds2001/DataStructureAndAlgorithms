#include <iostream>
#include <string>
#include <queue>
#include <deque>

using namespace std;

int n, m;
int mp[10 + 1][10 + 1];

int dp[10 + 1][10 + 1][2];
queue<int> routes;
deque<int> paths;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mp[i][j];
        }
    }

    routes.push(1);
    routes.push(1);

    while(!routes.empty()) {
        const int size = routes.size();

        for (int k = 1; k <= size / 2; ++k) {
            const int x = routes.front();
            routes.pop();
            const int y = routes.front();
            routes.pop();

            if (x == n && y == m) {
                int xx = n, yy = m;

                while (xx != 1 || yy != 1) {
                    const int y = dp[xx][yy][1];
                    const int x = dp[xx][yy][0];
                    paths.push_front(yy);
                    paths.push_front(xx);
                    yy = y;
                    xx = x;
                }

                paths.push_front(yy);
                paths.push_front(xx);

                while (!paths.empty()) {
                    const int x = paths.front();
                    paths.pop_front();
                    const int y = paths.front();
                    paths.pop_front();
                    cout << '(' << (x - 1) << ',' << (y - 1) << ')' << endl;
                }

                goto END;
            }

            for (auto& d: dir) {
                int mx = x + d[0];
                int my = y + d[1];
                if (
                    mx > 0 &&
                    mx <= n &&
                    my > 0 &&
                    my <= m &&
                    mp[mx][my] == 0 &&
                    dp[mx][my][0] == 0 &&
                    dp[mx][my][1] == 0
                ) {
                    dp[mx][my][0] = x;
                    dp[mx][my][1] = y;
                    routes.push(mx);
                    routes.push(my);
                }
            }
        }
    }

    END:

    return 0;
}
