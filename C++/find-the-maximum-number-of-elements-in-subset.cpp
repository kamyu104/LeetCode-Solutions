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
        for (const auto& k_v : cnt) {
            int64_t x = k_v.first;
            if (x == 1) {
                result = max(result, cnt[x] - (cnt[x] % 2 == 0 ? 1 : 0));
                continue;
            }
            vector<int> stk;
            for (; !dp.count(x) && cnt.count(x) && cnt[x] >= 2; x *= x) {
                stk.emplace_back(x);
            }
            if (!dp.count(x)) {
                if (!cnt.count(x)) {
                    x = stk.back(); stk.pop_back();
                }
                dp[x] = 1;
            }
            int l = dp[x];
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
        for (const auto& k_v : cnt) {
            int64_t x = k_v.first;
            if (x == 1) {
                result = max(result, cnt[x] - (cnt[x] % 2 == 0 ? 1 : 0));
                continue;
            }
            int l = 0;
            for (; cnt.count(x) && cnt[x] >= 2; x *= x) {
                l += 2;
            }
            l += cnt.count(x) ? 1 : -1;
            result = max(result, l);
        }
        return result;
    }
};
