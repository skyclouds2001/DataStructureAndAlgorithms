#include <iostream>
#include <string>

using namespace std;

bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    long long input;
    cin >> input;
    long long num = input;

    while (num % 2 == 0) {
        cout << 2;
        if (num != 1) {
            cout << ' ';
        } else {
            cout << endl;
        }
        num /= 2;
    }

    for (int i = 3; i * i <= input; i += 2) {
        if (isPrime(i)) {
            while (num % i == 0) {
                cout << i;
                if (num != 1) {
                    cout << ' ';
                } else {
                    cout << endl;
                }
                num /= i;
            }
        }
        if (num == 1) {
            break;
        }
    }

    if (num != 1) {
        cout << num << endl;
    }

    return 0;
}
