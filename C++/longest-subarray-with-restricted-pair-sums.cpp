// Time:  O(n * r)
// Space: O(r)

// freq table, two pointers
class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        vector<int> cnt(ranges::max(nums) + 1);
        const auto& count = [&](int x) {
            return ranges::fold_left(views::iota(1, x / 2 + 1) | views::transform([&](int y) {
                       return y != x - y ? static_cast<int64_t>(cnt[y]) * cnt[x - y]
                                         : static_cast<int64_t>(cnt[y]) * (cnt[y] - 1) / 2;
                   }), static_cast<int64_t>(0), plus{}) +
                   ranges::fold_left(views::iota(1, static_cast<int>(size(cnt)) - x) | views::transform([&](int y) {
                       return static_cast<int64_t>(cnt[y]) * cnt[x + y];
                   }), static_cast<int64_t>(0), plus{});
        };

        int left = 0;
        int64_t total = 0;
        for (const auto& x : nums) {
            total += count(x);
            ++cnt[x];
            if (total) {
                --cnt[nums[left]];
                total -= count(nums[left++]);
            }
        }
        return size(nums) - left;
    }
};

// Time:  O(n * r)
// Space: O(r)
// freq table, two pointers
class Solution2 {
public:
    int maxSubarray(vector<int>& nums) {
        vector<int> cnt(ranges::max(nums) + 1);
        const auto& count = [&](int x) {
            return ranges::fold_left(views::iota(1, x / 2 + 1) | views::transform([&](int y) {
                       return y != x - y ? static_cast<int64_t>(cnt[y]) * cnt[x - y]
                                         : static_cast<int64_t>(cnt[y]) * (cnt[y] - 1) / 2;
                   }), static_cast<int64_t>(0), plus{}) +
                   ranges::fold_left(views::iota(1, static_cast<int>(size(cnt)) - x) | views::transform([&](int y) {
                       return static_cast<int64_t>(cnt[y]) * cnt[x + y];
                   }), static_cast<int64_t>(0), plus{});
        };

        int result = 0, left = 0;
        int64_t total = 0;
        for (const auto& [right, x] : views::enumerate(nums)) {
            total += count(x);
            ++cnt[x];
            while (total) {
                --cnt[nums[left]];
                total -= count(nums[left++]);
            }
            result = max<int>(result, right - left + 1);
        }
        return result;
    }
};

// Time:  O(n * r)
// Space: O(r)
// freq table, two pointers
class Solution3 {
public:
    int maxSubarray(vector<int>& nums) {
        vector<int> cnt(ranges::max(nums) + 1);
        const auto& check = [&](int x) {
            return ranges::all_of(views::iota(1, x / 2 + 1), [&](int y) {
                       return !cnt[y] || !cnt[x - y] || (y == x - y && cnt[y] <= 1);
                   }) &&
                   ranges::all_of(views::iota(1, static_cast<int>(size(cnt)) - x), [&](int y) {
                       return !cnt[y] || !cnt[x + y];
                   });
        };

        int result = 0, left = 0;
        for (const auto& [right, x] : views::enumerate(nums)) {
            while (!check(x)) {
                --cnt[nums[left++]];
            }
            ++cnt[x];
            result = max<int>(result, right - left + 1);
        }
        return result;
    }
};
