class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pl = p.length();
        int sl = s.length();

        vector<int> ans;
        
        if (sl < pl) {
            return ans;
        }

        vector<int> cmp(26);
        for (auto c: p) {
            ++cmp[c - 'a'];
        }

        vector<int> win(26);
        for (int i = 0; i < pl; ++i) {
            ++win[s[i] - 'a'];
        }

        if (cmp == win) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sl - pl; ++i) {
            --win[s[i] - 'a'];
            ++win[s[i + pl] - 'a'];
            if (cmp == win) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};
