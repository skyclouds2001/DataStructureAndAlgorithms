#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    int count = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int ir = (int)floor(sqrt((double)i));
        int sum = 0;

        for (int j = 1; j <= ir; ++j) {
            if (i % j == 0) {
                sum += j;
                if (i != j * j) {
                    sum += i / j;
                }
            }
        }

        if (i * 2 == sum) {
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}
