class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        std::set<char> set;
        for (auto ch: jewels) {
            set.insert(ch);
        }
        int count = 0;
        for (auto ch: stones) {
            if (set.find(ch) != set.end()) {
                ++count;
            }
        }
        return count;
    }
};
