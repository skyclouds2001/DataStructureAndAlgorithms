#include <iostream>
#include <string>
#include <bitset>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::bitset;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    bitset<20> bits(n);

    string bn = bits.to_string();

    int len = 0;
    int max_len = 0;
    for (auto c: bn) {
        switch (c) {
            case '0':
                len = 0;
                break;
            case '1':
                ++len;
                max_len = std::max(max_len, len);
                break;
        }
    }

    cout << max_len << endl;

    return 0;
}
