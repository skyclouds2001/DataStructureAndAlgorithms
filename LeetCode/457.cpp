class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        const int size = nums.size();
        bool flag = false;

        auto next = [&](const int cur) -> int {
            return ((cur + nums[cur]) % size + size) % size;
        };

        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                continue;
            }

            int fast = next(i), slow = i;

            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                if (fast == slow) {
                    if (slow != next(slow)) {
                        flag = true;
                        goto OUT;
                    } else {
                        break;
                    }
                }

                fast = next(next(fast));
                slow = next(slow);
            }

            int p = i;
            while (nums[p] * nums[next(p)] > 0) {
                int t = p;
                p = next(p);
                nums[t] = 0;
            }
        }

        OUT:

        return flag;
    }
};
