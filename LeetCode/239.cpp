class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;

        int size = nums.size();

        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            int val = nums.at(i);
            while (!que.empty() && val > que.back()) {
                que.pop_back();
            }
            que.push_back(val);
        }

        ans.push_back(que.front());

        for (int i = k; i < size; ++i) {
            if (!que.empty() && nums[i - k] == que.front()) {
                que.pop_front();
            }

            int val = nums.at(i);
            while (!que.empty() && val > que.back()) {
                que.pop_back();
            }
            que.push_back(val);

            ans.push_back(que.front());
        }

        return ans;
    }
};
