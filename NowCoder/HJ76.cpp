#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    int m;
    cin >> m;

    for (int i = m * m - m + 1; i < m * m + m - 1; i += 2) {
        cout << i << '+';
    }
    cout << m * m + m - 1 << endl;

    return 0;
}
