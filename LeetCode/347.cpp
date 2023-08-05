class Solution {
private:
    class comparison {
    public:
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto n: nums) {
            ++map[n];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, comparison> que;
        for (auto p = map.begin(); p != map.end(); ++p) {
            que.push(*p);
            if (que.size() > k) {
                que.pop();
            }
        }

        vector<int> result(k);

        for (int i = k - 1; i >= 0; --i) {
            result[i] = que.top().first;
            que.pop();
        }

        return result;
    }
};
