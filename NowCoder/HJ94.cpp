#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Candidate {
    string name;
    int votes;
};

int n;
vector<Candidate> candidates;

int m;

string ballot;
bool found;

int invalid_votes;

int main(int argc, char const *argv[]) {
    cin >> n;
    candidates.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].name;
        candidates[i].votes = 0;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> ballot;
        found = false;
        for (int j = 0; j < n; ++j) {
            if (candidates[j].name == ballot) {
                found = true;
                ++candidates[j].votes;
            }
        }
        if (!found) {
            ++invalid_votes;
        }
    }

    for (auto candidate: candidates) {
        cout << candidate.name << " : " << candidate.votes << endl;
    }
    cout << "Invalid : " << invalid_votes << endl;

    return 0;
}
