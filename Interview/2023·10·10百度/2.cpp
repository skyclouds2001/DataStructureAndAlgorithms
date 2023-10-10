#include <iostream>
#include "algorithm"
#include "vector"

using namespace std;

int n, k;
vector<int> vec;

int main() {
    cin >> n >> k;
    for (int i = 0, v; i < n; ++i) {
        cin >> v;
        vec.push_back(v);
    }

    sort(vec.begin(), vec.end());

    const int mid = n / 2;

    for (int i = mid + 1; i < n; ++i) {
        int abs = vec[i] - vec[i - 1];

        if (k - abs * (i - mid) < 0) {
            cout << vec[i - 1] + k / (i - mid) << endl;
            break;
        }
        if (k - abs * (i - mid) == 0) {
            cout << vec[i] << endl;
            break;
        }

        k -= abs * (i - mid);

        while (i < n - 1 && vec[i] == vec[i + 1]) {
            ++i;
        }
    }

    return 0;
}
