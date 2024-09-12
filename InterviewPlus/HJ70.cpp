#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

struct Matrix {
    int row;
    int column;
    Matrix() { }
    Matrix(int row, int column) : row(row), column(column) { }
};

int n;
Matrix matrix[15];
string order;
stack<Matrix> mtx;
stack<char> cmd;
int sum;

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> matrix[i].row >> matrix[i].column;
    }
    cin >> order;

    for (char c: order) {
        if (c == '(') {
            cmd.push(c);
        } else if (c == ')') {
            cmd.pop();
            Matrix mtx1 = mtx.top();
            mtx.pop();
            Matrix mtx2 = mtx.top();
            mtx.pop();
            Matrix mtx3 = Matrix(mtx1.row, mtx2.column);
            mtx.push(mtx3);
            sum += mtx1.row * mtx2.column * sqrt(mtx1.column * mtx2.row);
        } else {
            mtx.push(matrix[c - 'A']);
        }
    }

    cout << sum << endl;

    return 0;
}
