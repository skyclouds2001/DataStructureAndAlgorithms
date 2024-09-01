#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        p[i] += v[i];
    }
    int N1, N2;
    for (int i = 0; i < N - 1; ++i) {
        cin >> N1 >> N2;
        p[N1] += v[N2];
    }

    int ans = INT_MIN;
    for (int i = 0; i < N; ++i) {
        if (ans < p[i]) {
            ans = p[i];
        }
    }
    cout << ans << endl;

    return 0;
}
