#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;

int m, n;
int matrix[30][30];

// void find (int x, int y) {
//     if (x < 0 || y < 0 || x >= m || y >= n || matrix[x][y] != 0) {
//         return;
//     }
//     matrix[x][y] = 1;
//     find(x - 1, y);
//     find(x + 1, y);
//     find(x, y - 1);
//     find(x, y + 1);
// }

bool visited[30][30];
int pos[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // matrix[0][0] = 0;
    // find(0, 0);
    queue<int> q;
    q.push(0);
    q.push(0);
    while (!q.empty()) {
        const int size = q.size();
        for (int k = 0; k < size; k += 2) {
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();

            matrix[x][y] = 1;

            for (int p = 0; p < 4; ++p) {
                int px = x + pos[p][0];
                int py = y + pos[p][1];
                if (px >= 0 && py >= 0 && px < m && py < n && matrix[px][py] == 0 && !visited[px][py]) {
                    visited[px][py] = true;
                    q.push(px);
                    q.push(py);
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 1) {
                ++cnt;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
