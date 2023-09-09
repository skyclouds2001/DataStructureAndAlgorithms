#include "iostream"
#include "string"

using namespace std;

int n, k;
string s;
int value;

int main() {
    cin >> n >> k;
    cin >> s;

    int fast = 0, slow = 0;
    while (fast < n) {
        if (fast + 1 < n && s[fast] == s[fast + 1]) {
            fast = fast + 2;
        } else {
            s[slow] = s[fast];
            ++slow;
            ++fast;
        }
    }

    if (slow > k * 2) {
        value = slow - k * 2;
    } else {
        value = n % 2 == 0 ? 2 : 1;
    }

    cout << value << endl;

    return 0;
}
