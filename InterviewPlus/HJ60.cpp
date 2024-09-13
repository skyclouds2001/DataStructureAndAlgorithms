#include <iostream>
#include <string>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int n;

int main(int argc, char const *argv[]) {
    cin >> n;

    for (int i = n / 2; i >= 2; --i) {
        if (is_prime(i) && is_prime(n - i)) {
            cout << i << endl << (n - i) << endl;
            break;
        }
    }

    return 0;
}
