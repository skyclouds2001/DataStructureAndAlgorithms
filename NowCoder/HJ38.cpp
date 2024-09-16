#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    double h;
    cin >> h;

    cout << (h + h + h / 2 + h / 4 + h / 8) << endl;
    cout << (h / 32) << endl;

    return 0;
}
