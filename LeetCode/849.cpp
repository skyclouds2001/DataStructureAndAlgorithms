class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = 0, r = 0;
        int ans = 0;

        for (auto seat: seats) {
            if (seat == 0) {
                if (r == seats.size() - 1) {
                    ans = max(ans, r - l);
                }
                ++r;
            }
            if (seat == 1) {
                if (seats[l] == 1) {
                    ans = max(ans, (r - l) / 2);
                }
                if (seats[l] == 0 && l == 0) {
                    ans = max(ans, r - l);
                }
                l = r;
                ++r;
            }
        }

        return ans;
    }
};
