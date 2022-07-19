// Time:  O(q + n * t)
// Space: O(t + n + q)

// radix sort
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int max_t = 0;
        for (int i = 0; i < size(queries); ++i) {
            max_t = max(max_t, queries[i][1]);
        }
        vector<vector<pair<int, int>>> lookup(max_t + 1);
        for (int i = 0; i < size(queries); ++i) {
            lookup[queries[i][1]].emplace_back(queries[i][0], i);
        }
        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        vector<int> result(size(queries));
        for (int l = 1; l <= max_t; ++l) {
            vector<int> cnt(10);
            for (int i = 0; i < size(idxs); ++i) {
                const int d = nums[idxs[i]][size(nums[idxs[i]]) - l]- '0';
                ++cnt[d];
            }
            for (int d = 0; d < 9; ++d) {
                cnt[d + 1] += cnt[d];
            }
            vector<int> new_idxs(size(nums));
            for (int i = size(idxs) - 1; i >= 0; --i) {
                const int d = nums[idxs[i]][size(nums[idxs[i]]) - l] - '0';
                --cnt[d];
                new_idxs[cnt[d]] = idxs[i];
            }
            idxs = move(new_idxs);
            for (const auto& [k, i] : lookup[l]) {
                result[i] = idxs[k - 1];
            }
        }
        return result;
    }
};

// Time:  O(q * n * t) on average
// Space: O(n + q)
// quick select
class Solution2 {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        vector<int> result;
        for (const auto& q : queries) {
            nth_element(begin(idxs), begin(idxs) + (q[0] - 1), end(idxs),
                        [&](const auto& a, const auto& b) {
                            const int cmp = nums[a].compare(size(nums[a]) - q[1], string::npos,
                                                            nums[b], size(nums[b]) - q[1], string::npos);
                            return cmp ? cmp < 0 : a < b;
                        }
            );
            result.emplace_back(idxs[q[0] - 1]);
        }
        return result;
    }
};

// Time:  O(q + nlogn * t)
// Space: O(t + n + q)
// sort
class Solution3 {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int max_t = 0;
        for (int i = 0; i < size(queries); ++i) {
            max_t = max(max_t, queries[i][1]);
        }
        vector<vector<pair<int, int>>> lookup(max_t + 1);
        for (int i = 0; i < size(queries); ++i) {
            lookup[queries[i][1]].emplace_back(queries[i][0], i);
        }
        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        vector<int> result(size(queries));
        for (int t = 1; t <= max_t; ++t) {
            if (empty(lookup[t])) {
                continue;
            }
            sort(begin(idxs), end(idxs),
                       [&](const auto& a, const auto& b) {
                           const int cmp = nums[a].compare(size(nums[a]) - t, string::npos,
                                                           nums[b], size(nums[b]) - t, string::npos);
                           return cmp ? cmp < 0 : a < b;
                       }
            );
            for (const auto& [k, i] : lookup[t]) {
                result[i] = idxs[k - 1];
            }
        }
        return result;
    }
};
