// Time:  O(nlogn)
// Space: O(n)

// sort, two pointers, dp
class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        ranges::sort(meetings); 
        vector<int> idxs(size(meetings));
        ranges::iota(idxs, 0);
        ranges::sort(idxs, {}, [&](int i) { return meetings[i][1]; });
        int64_t result = 0;
        vector<int64_t> dp(size(meetings));
        for (int64_t i = 0, idx = 0, mx = numeric_limits<int64_t>::min(); i < size(meetings); ++i) {
            const auto& s = meetings[i][0], r = meetings[i][2];
            for (; meetings[idxs[idx]][1] <= s; ++idx) {
                mx = max(mx, dp[idxs[idx]] - meetings[idxs[idx]][1]);
            }
            dp[i] = r + max<int64_t>(s + mx, 0);
            result = max(result, dp[i]);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, binary search, prefix sum, dp
class Solution2 {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        ranges::sort(meetings, {}, [](const auto& x) { return x[1]; }); 
        vector<int> ends(size(meetings));
        ranges::transform(meetings, begin(ends), [](const auto& m) { return m[1]; });
        int64_t result = 0;
        vector<int64_t> prefix(size(meetings) + 1, numeric_limits<int64_t>::min());
        for (int i = 0; i < size(meetings); ++i) {
            const auto& s = meetings[i][0], &e = meetings[i][1], &r = meetings[i][2];
            const auto& dp = r + max<int64_t>(s + prefix[distance(begin(ends), ranges::upper_bound(ends, s))], 0);
            result = max(result, dp);
            prefix[i + 1] = max(prefix[i], dp - e);
        }
        return result;
    }
};
