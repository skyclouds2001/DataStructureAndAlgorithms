#include "iostream"

using namespace std;

int n;
int a[50000], b[50000], c[50000], d[50000];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i] && c[i] < d[i] || a[i] < b[i] && c[i] > d[i]) {
            ++count;
        }
    }
    cout << count << endl;

    return 0;
}
