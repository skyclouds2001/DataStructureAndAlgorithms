#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

struct Item {
    int v;
    int p;
    int q;
    int w;
    Item(int v, int p, int q, int w) {
        this -> v = v;
        this -> p = p;
        this -> q = q;
        this -> w = w;
    }
};

int N, m;
map<int, vector<Item*>> its;
vector<vector<Item*>> res;
int dp[60 + 1][32000 + 1];

int v, p, q;

int main(int argc, char const *argv[]) {
    cin >> N >> m;

    for (int k = 1; k <= m; ++k) {
        cin >> v >> p >> q;
        Item * it = new Item(v, p, q, v * p);
        if (q == 0) {
            its[k].push_back(it);
        } else {
            its[q].push_back(it);
        }
    }

    for (auto u: its) {
        res.push_back(u.second);
    }

    int n = res.size();
    for (int i = 1; i <= n; ++i) {
        auto items = res[i - 1];

        if (items.size() == 2) {
            if (items[0] -> q == 0) {
                items[1] -> v += items[0] -> v;
                items[1] -> w += items[0] -> w;
            }
            if (items[1] -> q == 0) {
                items[0] -> v += items[1] -> v;
                items[0] -> w += items[1] -> w;
            }
        }
        if (items.size() == 3) {
            items.push_back(new Item(items[0] -> v + items[1] -> v + items[2] -> v, 0, 0, items[0] -> w + items[1] -> w + items[2] -> w));
            if (items[0] -> q == 0) {
                items[1] -> v += items[0] -> v;
                items[1] -> w += items[0] -> w;
                items[2] -> v += items[0] -> v;
                items[2] -> w += items[0] -> w;
            }
            if (items[1] -> q == 0) {
                items[0] -> v += items[1] -> v;
                items[0] -> w += items[1] -> w;
                items[2] -> v += items[1] -> v;
                items[2] -> w += items[1] -> w;
            }
            if (items[2] -> q == 0) {
                items[0] -> v += items[2] -> v;
                items[0] -> w += items[2] -> w;
                items[1] -> v += items[2] -> v;
                items[1] -> w += items[2] -> w;
            }
        }

        for (int j = 10; j <= N; j += 10) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            for (auto& item: items) {
                if (j >= item -> v) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - item-> v] + item -> w);
                }
            }
        }
    }

    cout << dp[n][N] << endl;

    return 0;
}
