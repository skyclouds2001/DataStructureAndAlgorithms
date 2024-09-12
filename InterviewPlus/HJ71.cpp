#include <cctype>
#include <iostream>
#include <string>
#include <map>

using namespace std;

string key, str;
int skl, ssl;
map<string, int> mp;

bool find(int ki, int si) {
    string ky = to_string(ki) + "-" + to_string(si);
    if (mp.count(ky) > 0) {
        return mp[ky];
    }

    if (ki == skl && si == ssl) {
        mp[ky] = true;
        return true;
    }
    if (ki == skl || si == ssl) {
        mp[ky] = false;
        return false;
    }

    char c1 = tolower(key[ki]), c2 = tolower(str[si]);

    if (c1 == '*') {
        bool flag = false;
        flag = flag || find(ki + 1, si);
        for (int k = 1; k < ssl - si; ++k) {
            if (!isalnum(str[si + k - 1])) {
                break;
            }
            flag = flag || find(ki + 1, si + k);
        }
        flag = flag || find(ki + 1, ssl);
        mp[ky] = flag;
        return flag;
    } else if (c1 == '?') {
        if (!isalnum(c2)) {
            mp[ky] = false;
            return false;
        }
        bool flag = find(ki + 1, si + 1);
        mp[ky] = flag;
        return flag;
    } else {
        if (c1 != c2) {
            mp[ky] = false;
            return false;
        } else {
            bool flag = find(ki + 1, si + 1);
            mp[ky] = flag;
            return flag;
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> key >> str;
    skl = key.length();
    ssl = str.length();

    cout << (find(0, 0) ? "true" : "false") << endl;

    return 0;
}
