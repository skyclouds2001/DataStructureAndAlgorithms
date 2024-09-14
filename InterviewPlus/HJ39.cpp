#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <functional>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::stringstream;
using std::getline;
using std::function;
using std::stoi;

template<typename T>
vector<T> split(const string& str, const char delimiter, const function<T(string)>& transformer) {
    vector<T> tokens;
    string token;
    stringstream ss(str);

    while (getline(ss, token, delimiter)) {
        tokens.push_back(transformer(token));
    }

    return tokens;
}

int main(int argc, char const *argv[]) {
    string mask, ip1, ip2;
    cin >> mask >> ip1 >> ip2;

    const auto transform = [](string str) -> int {
        return stoi(str);
    };
    auto masks = split<int>(mask, '.', transform);
    auto ip1s = split<int>(ip1, '.', transform);
    auto ip2s = split<int>(ip2, '.', transform);

    bool valid = true;
    if (masks[0] != 255 || masks[3] != 0 || masks[1] >= 256 || masks[2] >= 256) {
        valid = false;
    }
    for (int i = 0; i < 4 && valid; ++i) {
        if (ip1s[i] >= 256 || ip2s[i] >= 256 || masks[i] < 0 || ip1s[i] < 0 || ip2s[i] < 0) {
            valid = false;
        }
    }
    if (!valid) {
        cout << 1 << endl;
        return 0;
    }

    bool effective = true;
    for (int i = 0; i < 4 && effective; ++i) {
        ip1s[i] = ip1s[i] & masks[i];
        ip2s[i] = ip2s[i] & masks[i];
        if (ip1s[i] != ip2s[i]) {
            effective = false;
            break;
        }
    }
    if (!effective) {
        cout << 2 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
