#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int matrix[9 + 1][9 + 1];

bool resolve();

int main(int argc, char const *argv[]) {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> matrix[i][j];
        }
    }

    resolve();

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

bool resolve() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (matrix[i][j] != 0) {
                continue;
            }

            vector<bool> ok(9 + 1, true);

            for (int k = 1; k <= 9; ++k) {
                ok[matrix[i][k]] = false;
            }
            for (int k = 1; k <= 9; ++k) {
                ok[matrix[k][j]] = false;
            }

            for (int p = 0; p <= 2; ++p) {
                for (int q = 0; q <= 2; ++q) {
                    if ((i - 1) / 3 * 3 + 1 + p <= 9 && (j - 1) / 3 * 3 + 1 + q <= 9) {
                        ok[matrix[(i - 1) / 3 * 3 + 1 + p][(j - 1) / 3 * 3 + 1 + q]] = false;
                    }
                }
            }

            for (int k = 1; k <= 9; ++k) {
                if (ok[k]) {
                    matrix[i][j] = k;
                    if (resolve()) {
                        return true;
                    }
                    matrix[i][j] = 0;
                }
            }

            return false;
        }
    }

    return true;
}
