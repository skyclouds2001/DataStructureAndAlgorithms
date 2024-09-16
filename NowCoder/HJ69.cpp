#include <iostream>
#include <string>

using namespace std;

int x, y, z;
int axy[100][100], byz[100][100];
int cxz[100][100];

int main(int argc, char const *argv[]) {
    cin >> x >> y >> z;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> axy[i][j];
        }
    }
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < z; ++j) {
            cin >> byz[i][j];
        }
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < z; ++j) {
            for (int k = 0; k < y; ++k) {
                cxz[i][j] += axy[i][k] * byz[k][j];
            }
        }
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < z; ++j) {
            cout << cxz[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
