// Time:  O(n)
// Space: O(n)

// freq table, dp
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int64_t, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        unordered_map<int64_t, int> dp;
        int result = 0;
        for (const auto& [x, _] : cnt) {
            if (x == 1) {
                result = max(result, cnt[x] - (cnt[x] % 2 == 0 ? 1 : 0));
                continue;
            }
            vector<int> stk;
            int64_t nx = x;
            for (; !dp.count(nx) && cnt.count(nx) && cnt[nx] >= 2; nx *= nx) {
                stk.emplace_back(nx);
            }
            if (!dp.count(nx)) {
                if (!cnt.count(nx)) {
                    nx = stk.back(); stk.pop_back();
                }
                dp[nx] = 1;
            }
            int l = dp[nx];
            while (!empty(stk)) {
                l += 2;
                dp[stk.back()] = l; stk.pop_back();
            }
            result = max(result, l);
        }
        return result;
    }
};

// Time:  O(n * log(logr)) = O(9 * n)
// Space: O(n)
// freq table
class Solution2 {
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
