#include <iostream>
#include <string>

using namespace std;

int n;

int main(int argc, char const *argv[]) {
    cin >> n;

    if (n == 1 || n == 2) {
        cout << -1 << endl;
    } else {
        switch (n % 4) {
            case 3:
                cout << 2 << endl;
                break;
            case 0:
                cout << 3 << endl;
                break;
            case 1:
                cout << 2 << endl;
                break;
            case 2:
                cout << 4 << endl;
                break;
        }
    }

    return 0;
}
