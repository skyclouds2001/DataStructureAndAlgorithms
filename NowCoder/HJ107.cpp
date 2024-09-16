#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {
    double num;
    cin >> num;

    double low = min(num, -1.0);
    double high = max(1.0, num);

    while (true) {
        double mid = (low + high) / 2.0;
        double cube = mid * mid * mid;
        if (abs(cube - num) < 0.01) {
            cout << fixed << setprecision(1) << mid << endl;
            break;
        }
        if (cube > num) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return 0;
}
