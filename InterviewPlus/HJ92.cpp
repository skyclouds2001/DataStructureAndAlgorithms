#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
vector<string> list;
string s;
int len;

bool cmp(const string& a, const string& b) {
    return a.length() > b.length();
}

int main(int argc, char const *argv[]) {
    while (cin >> str) {
        list.clear();

        for (auto c: str) {
            if (isdigit(c)) {
                s += c;
            } else {
                if (s.length() > 0) {
                    list.push_back(s);
                    s.clear();
                }
            }
        }

        if (s.length() > 0) {
            list.push_back(s);
            s.clear();
        }

        sort(list.begin(), list.end(), cmp);
        len = list.at(0).length();
        for (auto& s: list) {
            if (s.length() == len) {
                cout << s;
            } else {
                break;
            }
        }
        cout << ',' << len << endl;
    }

    return 0;
}
