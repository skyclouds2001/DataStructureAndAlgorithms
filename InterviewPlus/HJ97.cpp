#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

int m, n;

int ng_cnt;
int po_cnt;
int po_ttl;
double po_aver;

int main(int argc, char const *argv[]) {
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> n;
        if (n < 0) {
            ++ng_cnt;
        } else if (n > 0) {
            ++po_cnt;
            po_ttl += n;
        }
    }

    if (po_ttl > 0) {
        po_aver = round(10.0 * po_ttl / po_cnt) / 10.0;
    } else {
        po_aver = 0;
    }

    cout << ng_cnt << ' ' << fixed << setprecision(1) << po_aver << endl;

    return 0;
}
