#include <iostream>
#include <string>

using namespace std;

int n;
int list[200];

int max_step;

void find(int pos, int step) {
    max_step = max(max_step, step);

    for (int k = pos + 1; k < n; ++k) {
        if (list[k] > list[pos]) {
            find(k, step + 1);
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int k = 0; k < n; ++k) {
      cin >> list[k];
    }

    for (int k = 0; k < n; ++k) {
        find(k, 1);
    }

    cout << max_step << endl;

    return 0;
}
