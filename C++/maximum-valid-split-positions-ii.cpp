// Time:  O(n + (logr)^2)) = O(n)
// Space: O(n + logr) = O(n)

// number theory, prefix sum
class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        // Time: O(n + logr), Space: O(n)
        const auto& prefix_gcd = [&](const auto& nums) {
            vector<int> prefix(size(nums) + 1);
            for (int i = 0; i < size(nums); ++i) {
                prefix[i + 1] = gcd(prefix[i], nums[i]);
            }
            return prefix;
        };

        // Time: O(n + logr), Space: O(n)
        const auto& suffix_gcd = [&](const auto& nums) {
            vector<int> suffix(size(nums) + 1);
            for (int i = size(nums) - 1; i >= 0; --i) {
                suffix[i] = gcd(suffix[i + 1], nums[i]);
            }
            return suffix;
        };

        // Time: O(n + (logr)^2), Space: O(n)
        const auto& diff = [&](const auto& nums, const auto& candidates) {
            // Time: O(1), Space: O(1)
            const auto& add = [](auto& groups, int x, int left, int right) {
                if (!empty(groups) && get<0>(groups.back()) == x) {
                    get<2>(groups.back()) = right;
                } else {
                    groups.emplace_back(x, left, right);
                }
            };

            // Time: O(1), Space: O(1)
            const auto& count = [](const auto& lookup, int x, int left, int right) {
                if (!lookup.count(x)) {
                    return 0;
                }
                const auto& [l, r] = lookup.at(x);
                return max(min(right, r) - max(left, l) + 1, 0);
            };

            vector<int> prefix = prefix_gcd(nums);
            vector<int> suffix = suffix_gcd(nums);
            unordered_map<int, pair<int, int>> lookup;
            int left = 0;
            while (left < size(nums)) {
                int right;
                for (right = left; right + 1 < size(nums) && suffix[right + 1] == suffix[left]; ++right);
                lookup[suffix[left]] = {left - 1, right - 1};
                left = right + 1;
            }
            vector<int> result(size(candidates));
            vector<tuple<int, int, int>> groups;
            for (int i = size(candidates) - 1; i >= 0; --i) {
                vector<tuple<int, int, int>> new_groups;
                int g = 0;
                for (int j = candidates[i] + 1, last = i + 1 < size(candidates) ? candidates[i + 1] : size(nums) - 1; j <= last; ++j) {
                    g = gcd(g, nums[j]);
                    add(new_groups, g, j, j);
                }
                for (const auto& [x, left, right] : groups) {
                    g = gcd(g, x);
                    add(new_groups, g, left, right);
                }
                groups = move(new_groups);
                int new_g = prefix[candidates[i]];
                int old_g = nums[candidates[i]];
                for (auto [x, left, right] : groups) {
                    new_g = gcd(new_g, x);
                    old_g = gcd(old_g, new_g);
                    right = min<int>(right, size(nums) - 2);
                    if (left > right) {
                        continue;
                    }
                    result[i] += count(lookup, new_g, left, right) - count(lookup, old_g, left, right);
                }
            }
            return result;
        };

        vector<int> prefix = prefix_gcd(nums);
        vector<int> suffix = suffix_gcd(nums);
        vector<int> candidates;
        for (int i = 0; i < size(nums); ++i) {
            if (prefix[i + 1] != prefix[i]) {
                candidates.emplace_back(i);
            }
        }
        vector<int> reversed_nums(rbegin(nums), rend(nums));
        vector<int> reversed_candidates;
        reversed_candidates.reserve(size(candidates));
        for (const auto& x : candidates | views::reverse) {
            reversed_candidates.emplace_back(size(nums) - 1 - x);
        }
        vector<int> left = diff(reversed_nums, reversed_candidates);
        vector<int> right = diff(nums, candidates);
        vector<bool> valid(size(nums) - 1);
        for (int i = 0; i < size(valid); ++i) {
            valid[i] = prefix[i + 1] == suffix[i + 1];
        }
        const auto& base = accumulate(cbegin(valid), cend(valid), 0);
        int result = base;
        for (int i = 0; i < size(candidates); ++i) {
            const auto& x = candidates[i];
            int total = base;
            total += left[size(left) - 1 - i];  // split < x-1
            if (x - 1 >= 0) {                   // split = x-1
                total += (prefix[x] == suffix[x + 1]) - valid[x - 1];
            }
            if (x < size(valid)) {              // split = x
                total += 0 - valid[x];
            }
            total += right[i];                  // split > x
            result = max(result, total);
        }
        return result;
    }
};

// Time:  O(logr * (n + logr)) = O(nlogr)
// Space: O(n)
// number theory, prefix sum
class Solution2 {
public:
    int maxValidSplits(vector<int>& nums) {
        // Time: O(n + logr), Space: O(n)
        const auto& count = [&](int skip) {
            vector<int> prefix(size(nums) + 1);
            for (int i = 0; i < size(nums); ++i) {
                prefix[i + 1] = i != skip ? gcd(prefix[i], nums[i]) : prefix[i];
            }
            vector<int> suffix(size(nums) + 1);
            for (int i = size(nums) - 1; i >= 0; --i) {
                suffix[i] = i != skip ? gcd(suffix[i + 1], nums[i]) : suffix[i + 1];
            }
            int result = 0;
            for (int i = 0; i + 1 < size(nums); ++i) {
                result += i != skip && prefix[i + 1] == suffix[i + 1];
            }
            return result;
        };

        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = gcd(prefix[i], nums[i]);
        }
        int result = count(-1);
        for (int i = 0; i < size(nums); ++i) {
            if (prefix[i + 1] != prefix[i]) {
                result = max(result, count(i));
            }
        }
        return result;
    }
};
