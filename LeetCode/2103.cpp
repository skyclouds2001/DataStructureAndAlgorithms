class Solution {
public:
    int countPoints(string rings) {
        const int size = rings.size();
        vector<vector<int>> v(10, vector<int>(3, 0));

        for (short i = 0; i < size / 2; ++i) {
            char c = rings[2 * i];
            short n = rings[2 * i + 1] - '0';

            switch (c) {
                case 'R':
                    ++v[n][0];
                    break;
                case 'G':
                    ++v[n][1];
                    break;
                case 'B':
                    ++v[n][2];
                    break;
            }
        }

        short cnt = 0;

        for (short k = 0; k < 10; ++k) {
            if (v[k][0] != 0 && v[k][1] != 0 && v[k][2] != 0) {
                ++cnt;
            }
        }

        return cnt;
    }
};
