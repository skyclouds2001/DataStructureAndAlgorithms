#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string sentence;
    string word;
    vector<string> words;

    getline(cin, sentence);

    for (auto c: sentence) {
        if (isalpha(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                words.push_back(string(word));
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        words.push_back(word);
        word.clear();
    }

    for (int pos = words.size() - 1; pos >= 0; --pos) {
        cout << words[pos] << ' ';
    }
    cout << endl;

    return 0;
}
