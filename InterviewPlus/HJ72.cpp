#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    for (int i = 0; i < 4; ++i) {
        cout << 4 * i << ' ' << 25 - 7 * i << ' ' << 75 + 3 * i << endl;
    }

    return 0;
}
