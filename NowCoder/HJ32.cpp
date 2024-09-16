#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int ans = 0;
    cin >> str;

    const int size = str.size();

    for (int i = 0; i < size; ++i) {
        int k = 0;
        while (i - k >= 0 && i + k < size && str[i - k] == str[i + k]) {
            ++k;
        }
        ans = max(ans, k * 2 - 1);
    }

    for (int i = 0; i < size - 1; ++i) {
        int k = 0;
        while (i - k >= 0 && i + k + 1 < size && str[i - k] == str[i + k + 1]) {
            ++k;
        }
        ans = max(ans, k * 2);
    }

    cout << ans << endl;

    return 0;
}
