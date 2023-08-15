class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (auto str: strs) {
            string hash = transformStringToHash(str);

            if (m.count(hash) == 0) {
                vector<string> v;
                v.push_back(str);
                m.insert(pair<string, vector<string>>(hash, v));
            } else {
                m.at(hash).push_back(str);
            }
        }

        vector<vector<string>> ans;
        for (auto an: m) {
            ans.push_back(an.second);
        }
        return ans;
    }

    string transformStringToHash(string s) {
        int sum[26] = {0};

        for (auto c: s) {
            ++sum[c - 'a'];
        }

        string res;
        for (auto s: sum) {
            res.append(" " + to_string(s));
        }

        return res;
    }
};
