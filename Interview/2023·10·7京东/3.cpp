#include "iostream"
#include "string"
#include "vector"

using namespace std;

int n, t;
int tn[2000 + 1], sn[2000 + 1], tp[2000 + 1], sp[2000 + 1];
int dp[2000 + 1][2000 + 1];
string ss[2000 + 1][2000 + 1];

int main() {
    cin >> n >> t;

    for (int i = 1; i <= n; ++i) {
        cin >> tn[i] >> sn[i] >> tp[i] >> sp[i];
    }

    // dp[n][t] = max(dp[n - 1][t], dp[n - 1][t - tn[n]] + sn[n], dp[n - 1][t - tp[n]] + sp[n])

    for (int nn = 1; nn <= n; ++nn) {
        for (int tt = 1; tt <= t; ++tt) {
            cout << "nn=" << nn << ' ' << "tt=" << tt << endl;
            cout << "tn[nn]=" << tn[nn] << ' ' << "sn[nn]=" << sn[nn] << ' ' << "tp[nn]=" << tp[nn] << ' ' << "sp[nn]=" << sp[nn] << endl;

            dp[nn][tt] = dp[nn - 1][tt];

            cout << "dp[nn - 1][tt]=" << dp[nn - 1][tt] << endl;

            if (tt >= tn[nn]) {
                dp[nn][tt] = max(dp[nn][tt], dp[nn - 1][tt - tn[nn]] + sn[nn]);

                cout << "dp[nn - 1][tt - tn[nn]] + sn[nn]" << (dp[nn - 1][tt - tn[nn]] + sn[nn]) << endl;
            }

            if (tt >= tp[nn]) {
                dp[nn][tt] = max(dp[nn][tt], dp[nn - 1][tt - tp[nn]] + sp[nn]);

                cout << "dp[nn - 1][tt - tp[nn]] + sp[nn])=" << (dp[nn - 1][tt - tp[nn]] + sp[nn]) << endl;
            }

            cout << "dp[nn][tt]=" << dp[nn][tt] << endl;

            if (dp[nn][tt] == dp[nn - 1][tt]) {
                ss[nn][tt] = ss[nn - 1][tt] + 'N';
            } else if (dp[nn][tt] == (dp[nn - 1][tt - tn[nn]] + sn[nn])) {
                ss[nn][tt] = ss[nn - 1][tt - tn[nn]] + 'A';
            } else if (dp[nn][tt] == (dp[nn - 1][tt - tp[nn]] + sp[nn])) {
                ss[nn][tt] = ss[nn - 1][tt - tp[nn]] + 'B';
            }
        }
    }

    cout << ss[n][t] << endl;

    return 0;
}
