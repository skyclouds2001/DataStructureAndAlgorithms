class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const long long MOD = 1000000000 + 7;
        const int hn = horizontalCuts.size();
        const int wn = verticalCuts.size();

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int hm = max(h - horizontalCuts[hn - 1], horizontalCuts[0] - 0);
        int wm = max(w - verticalCuts[wn - 1], verticalCuts[0] - 0);

        for (int i = 1; i < hn; ++i) {
            hm = max(hm, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < wn; ++i) {
            wm = max(wm, verticalCuts[i] - verticalCuts[i - 1]);
        }

        return (long long)hm * wm % MOD;
    }
};
