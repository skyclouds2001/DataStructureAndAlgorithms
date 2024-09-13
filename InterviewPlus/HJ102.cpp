#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

string str;
map<char, int> mp;

int main(int argc, char const *argv[]) {
    cin >> str;

    for (char& c: str) {
        ++mp[c];
    }

    vector<pair<char, int>> mv(mp.begin(), mp.end());

    sort(mv.begin(), mv.end(), [](const auto& a, const auto& b) {
        return a.second > b.second || a.second == b.second && a.first < b.first;
    });

    for (auto& cv: mv) {
        cout << cv.first;
    }
    cout << endl;

    return 0;
}
