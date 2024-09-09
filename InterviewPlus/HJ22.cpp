#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    while(true) {
        int cnt;
        cin >> cnt;

        if (cnt == 0) {
            break;
        }

        int ret = cnt;
        int ans = 0;
        while (ret != 0 && ret != 1) {
            int k = ret / 3;
            ans += k;
            ret -= k * 3;
            ret += k;

            if (ret == 2) {
                ans += 1;
                ret = 0;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
