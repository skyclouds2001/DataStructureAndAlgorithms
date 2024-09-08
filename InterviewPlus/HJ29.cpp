#include <iostream>
#include <string>

using namespace std;

string raw, secret;

int main() {
    raw = "";
    secret = "";

    cin >> raw;

    for (char c: raw) {
        if (c >= 'A' && c <= 'Z') {
            secret += (char)((c - 'A' + 1) % 26 + 'a');
        } else if (c >= 'a' && c <= 'z') {
            secret += (char)((c - 'a' + 1) % 26 + 'A');
        } else if (c >= '0' && c <= '9') {
            secret += (char)((c - '0' + 1) % 10 + '0');
        } else {
            secret += c;
        }
    }
    cout << secret << endl;

    raw = "";
    secret = "";

    cin >> secret;

    for (char c: secret) {
        if (c >= 'A' && c <= 'Z') {
            raw += (char)((c - 'A' - 1 + 26) % 26 + 'a');
        } else if (c >= 'a' && c <= 'z') {
            raw += (char)((c - 'a' - 1 + 26) % 26 + 'A');
        } else if (c >= '0' && c <= '9') {
            raw += (char)((c - '0' - 1 + 10) % 10 + '0');
        } else {
            raw += c;
        }
    }
    cout << raw << endl;

    return 0;
}
