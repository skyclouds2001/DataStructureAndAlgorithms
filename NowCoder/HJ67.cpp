#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double card[4];
bool visited[4] = {false, false, false, false};
bool flag = false;

void dfs(int step, double sum) {
    if (step == 4) {
        if (sum == 24) {
            flag = true;
        }
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;

        if (step == 0) {
            dfs(step + 1, card[i]);
        } else {
            dfs(step + 1, sum + card[i]);
            dfs(step + 1, sum - card[i]);
            dfs(step + 1, sum * card[i]);
            dfs(step + 1, sum / card[i]);
        }

        visited[i] = false;
    }
}

int main(int argc, char const *argv[]) {
    cin >> card[0] >> card[1] >> card[2] >> card[3];

    dfs(0, 0);

    cout << (flag ? "true" : "false") << endl;

    return 0;
}
