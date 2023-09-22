class Solution {
private:
    const int MOD = 1000000000 + 7;
    vector<long long> v;
public:
    /**
     * @param t string字符串
     * @return int整型
     */
    int cntOfMethod(string t) {
        const int size = t.length();
        v.resize(size);

        if (size <= 3) {
            return 1;
        }

        // v[n] = v[n-1] + v[n-2] | n-2 == n && n-3 == n-1

        v[0] = 1;
        v[1] = 1;
        v[2] = 1;

        // 'ababa'

        for (int n = 3; n < size; ++n) {
            v[n] = v[n - 1];

            if (v[n] != v[n - (n + 1) / 2]) {
                continue;
            }

            for (int k = n - 1; k >= (n + 1) / 2; --k) {
                if (v[k] != v[k - (n + 1) / 2]) {
                    break;
                }
                v[n] += v[k]; // MOD
            }

            v[n] %= MOD;
        }

        int count = v[size - 1];

        return count;
    }
};
