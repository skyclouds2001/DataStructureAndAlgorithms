class Solution {
public:
    string greatestLetter(string s) {
        string ans = "";
        int flags[26] = {0};
        for (auto c: s) {
            /**
             * * 0 - unmet
             * * 1 - lower
             * * 2 - upper
             * * 3 - both
             */
            if (islower(c)) {
                int step = c - 'a';
                cout << c << " " << step<< " " << flags[step] << endl;
                if (flags[step] == 0) {
                    flags[step] = 1;
                } else if (flags[step] == 2) {
                    flags[step] = 3;
                    if ((int)ans.length() == 0 || ans.at(0) < toupper(c)) {
                        ans = toupper(c);
                    }
                }
            } else if (isupper(c)) {
                int step = c - 'A';
                cout << c << " " << step<< " " << flags[step] << endl;
                if (flags[step] == 0) {
                    flags[step] = 2;
                } else if (flags[step] == 1) {
                    flags[step] = 3;
                    if ((int)ans.length() == 0 || ans.at(0) < c) {
                        ans = c;
                    }
                }
            }
        }
        return ans;
    }
};
