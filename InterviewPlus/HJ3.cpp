#include <iostream>
#include <set>

using namespace std;

int N;
int t;
set<int> st;

int main(int argc, char const *argv[]) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        st.insert(t);
    }

    for (auto& v: st) {
        cout << v << endl;
    }

    return 0;
}
