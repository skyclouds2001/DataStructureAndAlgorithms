class Solution {
public:
    int compress(vector<char>& chars) {
        const int size = chars.size();
        int fast = 0, slow = 0;
        int keep = 0;

        while (fast < size) {
            while(fast < size && chars[fast] == chars[slow]) {
                ++fast;
            }

            int num = fast - slow;
            if (num == 1) {
                chars[keep] = chars[slow];
                ++keep;
            } else {
                chars[keep] = chars[slow];
                ++keep;

                int anchor = keep;
                while (num > 0) {
                    chars[keep] = num % 10 + '0';
                    num /= 10;
                    ++keep;
                }

                reverse(&chars[anchor], &chars[keep]);
            }

            slow = fast;
        }

        chars.resize(keep);

        return keep;
    }
};
