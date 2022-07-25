// Time:  O(n + (logn)^2) = O(n)
// Space: O(n + logn) = O(n)

// bit manipulation, freq table, combinatorics
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        const auto& bit_length = [](int x) {
            return x != 0 ? 32 - __builtin_clz(x) : 1;
        };

        const int mx = *max_element(cbegin(nums), cend(nums));
        vector<int64_t> cnt(bit_length(mx) + 1);
        unordered_set<int> lookup;
        for (const auto& x : nums) {
            if (lookup.count(x)) {
                continue;
            }
            lookup.emplace(x);
            ++cnt[__builtin_popcount(x)];
        }
        int64_t result = 0;
        for (int i = 1; i < size(cnt); ++i) {
            for (int j = 1; j < size(cnt); ++j) {
                if (i + j >= k) {
                    result += cnt[i] * cnt[j];
                }
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// bit manipulation, sort, two pointers
class Solution2 {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        const auto& bit_length = [](int x) {
            return x != 0 ? 32 - __builtin_clz(x) : 1;
        };

        vector<int> sorted_cnts;
        unordered_set<int> lookup;
        for (const auto& x : nums) {
            if (lookup.count(x)) {
                continue;
            }
            lookup.emplace(x);
            sorted_cnts.emplace_back(__builtin_popcount(x));
        }
        sort(begin(sorted_cnts), end(sorted_cnts));
        int64_t result = 0;
        int left = 0, right = size(sorted_cnts) - 1;
        while (left <= right) {
            if (sorted_cnts[left] + sorted_cnts[right] < k) {
                ++left;
            } else {
                result += 1 + 2 * ((right - 1) - left + 1);
                --right;
            }
        }
        return result;
    }
};
