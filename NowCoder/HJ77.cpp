#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int trains[10];

deque<int> in;
deque<int> out;

vector<string> list;

void find(deque<int> in, deque<int> out, int order) {
    if (order + 1 == N) {
        string s;
        for (auto it = out.begin(); it != out.end(); ++it) {
            s += to_string(*it);
            s += ' ';
        }
        s += to_string(trains[order]);
        s += ' ';
        for (auto it = in.rbegin(); it != in.rend(); ++it) {
            s += to_string(*it);
            s += ' ';
        }
        list.push_back(s);
        return;
    }

  int train = trains[order];

  in.push_back(train);

  find(in, out, order + 1);

    while (!in.empty()) {
        int tr = in.back();
        in.pop_back();
        out.push_back(tr);

        find(in, out, order + 1);
    }
}

int main(int argc, char const *argv[]) {
    cin >> N;
    for (int k = 0; k < N; ++k) {
        cin >> trains[k];
    }

    find(in, out, 0);

    sort(list.begin(), list.end());

    for (auto s: list) {
        cout << s << endl;
    }

    return 0;
}
