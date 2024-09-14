#include <iostream>
#include <string>

using namespace std;

long long n;

int cnt;

int main(int argc, char const *argv[]) {
    cin >> n;

    for (long long i = 0; i <= n; ++i) {
        string is = to_string(i);
        string iis = to_string(i * i);
        if (is == iis.substr(iis.length() - is.length(), is.length())) {
            ++cnt;
        }
    }

    cout << cnt << endl;

    return 0;
}
