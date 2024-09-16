#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::unique;
using std::count_if;
using std::to_string;
using std::string;
using std::deque;

int main(int argc, char const *argv[]) {
    int I;
    cin >> I;
    vector<int> IList(I);
    for (int i = 0; i < I; ++i) {
        cin >> IList[i];
    }
    int R;
    cin >> R;
    vector<int> RList(R);
    for (int i = 0; i < R; ++i) {
        cin >> RList[i];
    }

    sort(RList.begin(), RList.end());
    auto it = unique(RList.begin(), RList.end());
    RList.erase(it, RList.end());

    deque<int> res;

    for (int R: RList) {
        int cnt = count_if(IList.begin(), IList.end(), [R](int val) {
            return to_string(val).find(to_string(R)) != string::npos;
        });
        if (cnt == 0) {
            continue;
        }

        res.push_back(R);
        res.push_back(cnt);
        for (int i = 0; i < I; ++i) {
            if (to_string(IList[i]).find(to_string(R)) != string::npos) {
                res.push_back(i);
                res.push_back(IList[i]);
            }
        }
    }

    res.push_front(res.size());

    for (int v: res) {
        cout << v << ' ';
    }
    cout << endl;

    return 0;
}
