#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;
int head;
vector<int> list;
int del;

int from, to;

int main(int argc, char const *argv[]) {
    cin >> num;
    cin >> head;
    list.push_back(head);
    for (int k = 0; k < num - 1; ++k) {
        cin >> to >> from;
        auto it = find(list.begin(), list.end(), from);
        list.insert(++it, to);
    }
    cin >> del;

    auto it = list.begin();
    while (it != list.end()) {
        auto pre = it;
        ++it;
        if (*pre == del) {
            list.erase(pre);
        }
    }

    for (auto c: list) {
        cout << c << ' ';
    }
    cout << endl;

    return 0;
}
