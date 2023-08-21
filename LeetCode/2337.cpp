class Solution {
public:
    bool canChange(string start, string target) {
        int lenS = start.length();
        int lenT = target.length();

        int s = 0, t = 0;

        bool flag = true;

        while (s < lenS && t < lenT) {
            while (s < lenS && start[s] == '_') {
                ++s;
            }
            while (t < lenT && target[t] == '_') {
                ++t;
            }

            if (s < lenS && t < lenT) {
                if (
                        start[s] != target[t] ||
                        start[s] == 'L' && target[t] == 'L' && s < t ||
                        start[s] == 'R' && target[t] == 'R' && s > t
                        ) {
                    flag = false;
                    break;
                }

                ++s;
                ++t;
            }
        }

        while (s < lenS) {
            if (start[s] != '_') {
                flag = false;
                break;
            }
            ++s;
        }

        while (t < lenT) {
            if (target[t] != '_') {
                flag = false;
                break;
            }
            ++t;
        }

        return flag;
    }
};
