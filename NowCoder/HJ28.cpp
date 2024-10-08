#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int n;
int k;
vector<int> odds, evens;
int count;
vector<int> matches;
vector<bool> used;

bool find(int v);

bool isPrime(int k);

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;

        if (k % 2 == 1) {
            odds.push_back(k);
        } else {
            evens.push_back(k);
        }
    }

    matches.resize(evens.size(), 0);

    for (int odd : odds) {
        used.resize(evens.size(), false);

        if (find(odd)) {
            ++count;
        }

        used.clear();
    }

    cout << count << endl;

    return 0;
}

bool find(int v) {
    for (int i = 0; i < evens.size(); ++i) {
        if (isPrime(v + evens[i]) && !used[i]) {
            used[i] = true;
            if (matches[i] == 0 || find(matches[i])) {
                matches[i] = v;
                return true;
            }
        }
    }
    return false;
}

bool isPrime(int k) {
    if (k <= 1) {
        return false;
    }

    if (k == 2) {
        return true;
    }

    if (k % 2 == 0) {
        return false;
    }

    for (int i = 3; i * i <= k; i += 2) {
        if (k % i == 0) {
            return false;
        }
    }

    return true;
}
