#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    string str1, str2;
    cin >> str1 >> str2;

    string str = str1 + str2;

    const int size = str.size();
    for (int i = 0; i < size; i += 2) {
        for (int j = 0; j < size - i - 2; j += 2) {
            if (str[j] > str[j + 2]) {
                swap(str[j], str[j + 2]);
            }
        }
    }
    for (int i = 1; i < size; i += 2) {
        for (int j = 1; j < size - i - 1; j += 2) {
            if (str[j] > str[j + 2]) {
                swap(str[j], str[j + 2]);
            }
        }
    }

    for (char& c: str) {
        int val = 0;
        if (c >= '0' && c <= '9') {
            val = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            val = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            val = c - 'a' + 10;
        } else {
            continue;
        }
        string bit = bitset<4>(val).to_string();
        auto r_bit = bitset<4>(string(bit.rbegin(), bit.rend()));
        val = r_bit.to_ulong();
        if (val >= 10 && val <= 15) {
            c = val - 10 + 'A';
        } else if (val >= 0 && val <= 9) {
            c = val + '0';
        } else {
            continue;
        }
    }

    cout << str << endl;

    return 0;
}
