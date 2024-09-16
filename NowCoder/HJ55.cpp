#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    string s;
    int cnt = 0;
    char ch = '7';
    for (int i = 1; i <= n; i++) {
        if (i % 7 == 0) {
            ++cnt;
        } else {
            s = to_string(i);
            if (s.find(ch) != string::npos) {
                ++cnt;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
