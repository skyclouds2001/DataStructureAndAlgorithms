#include <iostream>
#include <deque>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::deque;
using std::sort;

int main(int argc, char const *argv[]) {
    int n, m;
    deque<int> nn, mm;

    cin >> n;
    nn.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nn[i];
    }
    cin >> m;
    mm.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> mm[i];
    }

    sort(nn.begin(), nn.end());
    sort(mm.begin(), mm.end());

    deque<int> res;
    while (!nn.empty() && !mm.empty()) {
        if (nn.front() == mm.front()) {
            if (res.empty() || res.back() != nn.front()) {
                res.push_back(nn.front());
            }
            nn.pop_front();
            mm.pop_front();
        } else if (nn.front() < mm.front()) {
            if (res.empty() || res.back() != nn.front()) {
                res.push_back(nn.front());
            }
            nn.pop_front();
        } else if (nn.front() > mm.front()) {
            if (res.empty() || res.back() != mm.front()) {
                res.push_back(mm.front());
            }
            mm.pop_front();
        }
    }
    while (!nn.empty()) {
        if (res.empty() || res.back() != nn.front()) {
            res.push_back(nn.front());
            nn.pop_front();
        }
    }
    while (!mm.empty()) {
        if (res.empty() || res.back() != mm.front()) {
            res.push_back(mm.front());
            mm.pop_front();
        }
    }

    for (int v: res) {
        cout << v;
    }
    cout << endl;

    return 0;
}
