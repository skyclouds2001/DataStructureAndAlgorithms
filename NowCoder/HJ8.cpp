#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    int index, value;
    map<int, int> map;
    for (int i = 0; i < n; ++i) {
        cin >> index >> value;
        if (map.find(index) != map.end()) {
            map[index] += value;
        } else {
            map.insert(pair<int, int>(index, value));
        }
    }

    for (const auto& v : map) {
        cout << v.first << ' ' << v.second << endl;
    }

    return 0;
}
