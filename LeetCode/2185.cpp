class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int num = 0;
        for(auto it: words) {
            size_t t = it.find(pref);
            if (t != string::npos && t == 0) ++num;
        }
        return num;
    }
};
