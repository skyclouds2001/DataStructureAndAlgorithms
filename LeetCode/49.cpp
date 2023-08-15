#include "vector"
#include "string"
#include "map"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto& str: strs) {
            string hash = str;
            sort(hash.begin(), hash.end());
            m[hash].emplace_back(str);
        }

        vector<vector<string>> ans;
        for (auto an: m) {
            ans.emplace_back(an.second);
        }
        return ans;
    }
};
