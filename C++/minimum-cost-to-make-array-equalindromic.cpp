// Time:  O(n + logr)
// Space: O(logr)

// lc0564
// quick select, math, string
class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        const auto& nearest_palindromic = [](int x) {
            const auto& n = to_string(x);
            const auto l = size(n);
            unordered_set<long long> result;
            result.emplace(static_cast<long long>(pow(10, l)) + 1);
            result.emplace(static_cast<long long>(pow(10, l - 1)) - 1);
            auto prefix = stol(n.substr(0, (l + 1) / 2));
            for (long long i = -1; i <= 1; ++i) {
                auto p = to_string(prefix + i);
                auto pp = p + string(p.rbegin() + (l % 2), p.rend());
                result.emplace(stol(pp));
            }
            return result;
        };

        nth_element(begin(nums), begin(nums) + size(nums) / 2, end(nums));
        int median = nums[size(nums) / 2];
        if (size(nums) % 2 == 0) {
            nth_element(begin(nums), begin(nums) + (size(nums) / 2 - 1), end(nums));
            median = (median + nums[size(nums) / 2 - 1]) / 2;
        }
        int64_t result = numeric_limits<int64_t>::max();
        for (const auto& p : nearest_palindromic(median)) {
            result = min(result, accumulate(cbegin(nums), cend(nums), static_cast<int64_t>(0ll), [&](const auto& accu, const auto& x) {
                return accu + abs(x - p);
            }));
        }
        return result;
    }
};

// Time:  O(nlogn + logr)
// Space: O(logr)
// lc0564
// sort, math, string
class Solution2 {
public:
    long long minimumCost(vector<int>& nums) {
        const auto& nearest_palindromic = [](int x) {
            const auto& n = to_string(x);
            const auto l = size(n);
            unordered_set<long long> result;
            result.emplace(static_cast<long long>(pow(10, l)) + 1);
            result.emplace(static_cast<long long>(pow(10, l - 1)) - 1);
            auto prefix = stol(n.substr(0, (l + 1) / 2));
            for (long long i = -1; i <= 1; ++i) {
                auto p = to_string(prefix + i);
                auto pp = p + string(p.rbegin() + (l % 2), p.rend());
                result.emplace(stol(pp));
            }
            return result;
        };

        sort(begin(nums), end(nums));
        int median = nums[size(nums) / 2];
        if (size(nums) % 2 == 0) {
            median = (median + nums[size(nums) / 2 - 1]) / 2;
        }
        int64_t result = numeric_limits<int64_t>::max();
        for (const auto& p : nearest_palindromic(median)) {
            result = min(result, accumulate(cbegin(nums), cend(nums), static_cast<int64_t>(0ll), [&](const auto& accu, const auto& x) {
                return accu + abs(x - p);
            }));
        }
        return result;
    }
};
