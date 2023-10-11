class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback,
                            vector<string>& negative_feedback,
                            vector<string>& report,
                            vector<int>& student_id,
                            int k) {
        unordered_set<string> ps(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> ns(negative_feedback.begin(), negative_feedback.end());
        const int size = student_id.size();
        vector<vector<int>> data;
        vector<int> ans;

        int score;
        string word;
        for (int i = 0; i < size; ++i) {
            score = 0;

            stringstream ss;
            ss << report[i];

            while (ss >> word) {
                if (ps.count(word) == 1) {
                    score += 3;
                }
                if (ns.count(word) == 1) {
                    score -= 1;
                }
            }

            data.push_back({-score, student_id[i]});
        }

        sort(data.begin(), data.end());

        for (int i = 0; i < k; ++i) {
            ans.push_back(data[i][1]);
        }

        return ans;
    }
};
