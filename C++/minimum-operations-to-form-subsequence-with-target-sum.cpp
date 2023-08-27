// Time:  O(nlogr)
// Space: O(logr)

// codeforces, https://codeforces.com/problemset/problem/1303/D
// bitmasks, greedy
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        const auto& floor_log2_x = [](int x) {
            return 8 * sizeof(int) - __builtin_clz(x) - 1;
        };

        if (accumulate(begin(nums), end(nums), 0ll) < target) {
            return -1;
        }

        vector<int> cnt(floor_log2_x(*max_element(cbegin(nums), cend(nums))) + 1);
        for (const auto& x : nums) {
            ++cnt[floor_log2_x(x)];
        }
        int result = 0, i = 0;
        while (i < size(cnt)) {
            if (target & (1 << i)) {
                if (!cnt[i]) {
                    for (; i < size(cnt) && !cnt[i]; ++i) {
                        ++result;
                    }
                    --cnt[i];
                    continue;
                }
                --cnt[i];
            }
            if (i + 1 < size(cnt)) {
                cnt[i + 1] += cnt[i] / 2;
            }
            ++i;
        }
        return result;
    }
};
