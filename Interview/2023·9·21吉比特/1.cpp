class Solution {
public:
    /**
     * @param distance int整型vector
     * @return bool布尔型
     */
    bool isSelfCrossing(vector<int>& distance) {
        set<string> s;

        int x = 0;
        int y = 0;

        bool flag = false;

        for (int kk = 0; kk < distance[0]; ++kk) {
            const string k = to_string(x) + "-" + to_string(y);

            if (s.count(k) == 1) {
                flag = true;
                goto END;
            }

            s.insert(k);

            ++y;
        }

        for (int kk = 0; kk < distance[1]; ++kk) {
            const string k = to_string(x) + "-" + to_string(y);

            if (s.count(k) == 1) {
                flag = true;
                goto END;
            }

            s.insert(k);

            --x;
        }

        for (int kk = 0; kk < distance[2]; ++kk) {
            const string k = to_string(x) + "-" + to_string(y);

            if (s.count(k) == 1) {
                flag = true;
                goto END;
            }

            s.insert(k);
            --y;
        }

        for (int kk = 0; kk < distance[3]; ++kk) {
            const string k = to_string(x) + "-" + to_string(y);

            if (s.count(k) == 1) {
                flag = true;
                goto END;
            }

            s.insert(k);
            ++x;
        }

        END:

        return flag;
    }
};
