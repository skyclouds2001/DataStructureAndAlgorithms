#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int n;

int ng_cnt;
int po_cnt;
int po_ttl;
string po_aver;

int main(int argc, char const *argv[]) {
    while (cin >> n) {
        if (n < 0) {
            ++ng_cnt;
        } else {
            ++po_cnt;
            po_ttl += n;
        }
    }

    if (po_cnt > 0) {
        po_aver = to_string((round(10 * po_ttl / po_cnt) / 10));
    } else {
        po_aver = "0.0";
    }

    cout << ng_cnt << endl << po_aver << endl;

    return 0;
}
