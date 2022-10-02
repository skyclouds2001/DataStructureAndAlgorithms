#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int step = 0;

    while (n != 1) {
        if (n & 1)
            n = (3 * n + 1) / 2;
        else
            n = n / 2;

        ++step;
    }

    cout << step << endl;

    return 0;
}