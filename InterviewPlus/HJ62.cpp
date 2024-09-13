#include <iostream>
#include <string>

using namespace std;

int n;
int cnt;

int main(int argc, char const *argv[]) {
    while(cin >> n) {
        while (n != 0) {
            if (n % 2 == 1) {
                cnt++;
            }
            n /= 2;
        }

        cout << cnt << endl;

        n = 0;
        cnt = 0;
    }

    return 0;
}
