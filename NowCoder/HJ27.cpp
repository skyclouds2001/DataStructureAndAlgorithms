#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool is_bro(string& word, string& x, map<char, int>& count) {
    if (word.length() != x.length()) {
        return false;
    }
    map<char, int> mp;
    for (auto c: word) {
        mp[c] += 1;
    }
    for (auto k: count) {
        if (k.second != mp[k.first]) {
            return false;
        }
    }
    if (word == x) {
        return false;
    }
    return true;
}

int main() {
    int m;
    vector<string> words;
    string word;
    string x;
    int k;
    vector<string> bro_words;
    map<char, int> count;

    cin >> m;
    for (int k = 0; k < m; ++k) {
        cin >> word;
        words.push_back(word);
    }
    cin >> x;
    cin >> k;

    for (auto c: x) {
        count[c] += 1;
    }
    for (auto word: words) {
        if (is_bro(word, x, count)) {
            bro_words.push_back(word);
        }
    }

    sort(bro_words.begin(), bro_words.end());

    cout << bro_words.size() << endl;
    if (k < bro_words.size()) {
        cout << bro_words[k - 1] << endl;
    }

    return 0;
}
