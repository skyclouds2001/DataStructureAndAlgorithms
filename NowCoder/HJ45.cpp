#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int N;
std::string str;
std::map<char, int> mp;
int total;
int weight = 26;

struct Data {
    char letter;
    int count;
    Data(char c, int cnt): letter(c), count(cnt) {}
};

std::vector<Data> vp;

bool cmp(Data& a, Data& b) {
    return a.count > b.count;
}

int main(int argc, char const *argv[]) {
    std::cin >> N;
    while (N > 0) {
        --N;

        std::cin >> str;

        for (auto ch: str) {
            ++mp[ch];
        }

        for (auto& m: mp) {
            vp.push_back(Data(m.first, m.second));
        }

        std::sort(vp.begin(), vp.end(), cmp);

        for (auto& v: vp) {
            total += v.count * weight;
            --weight;
        }

        std::cout << total << std::endl;

        mp.clear();
        vp.clear();
        total = 0;
        weight = 26;
    }

    return 0;
}
