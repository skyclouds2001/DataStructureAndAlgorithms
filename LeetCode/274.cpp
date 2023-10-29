class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;

        sort(citations.begin(), citations.end());

        int i = citations.size() - 1;
        while (i >= 0 && citations[i] > h) {
            ++h;
            --i;
        }

        return h;
    }
};
