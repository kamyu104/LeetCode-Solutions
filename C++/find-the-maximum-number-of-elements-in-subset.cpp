// Time:  O(n * log(logr)) = O(9 * n)
// Space: O(n)

// freq table
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int64_t, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        int result = 0;
        for (const auto& [x, _] : cnt) {
            if (x == 1) {
                result = max(result, cnt[x] - (cnt[x] % 2 == 0 ? 1 : 0));
                continue;
            }
            int l = 0;
            int64_t nx = x;
            for (; cnt.count(nx) && cnt[nx] >= 2; nx *= nx) {
                l += 2;
            }
            l += cnt.count(nx) ? 1 : -1;
            result = max(result, l);
        }
        return result;
    }
};
