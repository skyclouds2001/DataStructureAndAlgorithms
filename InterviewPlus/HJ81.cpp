#include <iostream>
#include <string>
#include <set>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::set;

int main(int argc, char const *argv[]) {
    string short_str, long_str;
    cin >> short_str;
    cin >> long_str;

    set<char> st;
    for (char c: long_str) {
        st.insert(c);
    }

    for (char c: short_str) {
        if (st.count(c) == 0) {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;

    return 0;
}
