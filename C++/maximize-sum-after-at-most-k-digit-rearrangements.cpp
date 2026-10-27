// Time:  O(nlogr)
// Space: O(n)

// quick select, greedy
class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        const auto& f = [](int n) {
            vector<int> cnt(10);
            for (int x = n; x; x /= 10) {
                ++cnt[x % 10];
            }
            int d = 0;
            for (int i = size(cnt) - 1; i >= 0; --i) {
                for (int _ = 0; _ < cnt[i]; ++_) {
                    d = d * 10 + i;
                }
            }
            return d - n;
        };

        vector<int> candidates(size(nums));
        for (const auto& [i, x] : views::enumerate(nums)) {
            candidates[i] = f(x);
        }
        nth_element(begin(candidates), begin(candidates) + (k - 1), end(candidates), greater<int>());
        int64_t result = accumulate(cbegin(nums), cend(nums), 0LL);
        for (int i = 0; i < k; ++i) {
            result += candidates[i];
        }
        return result;
    }
};
