// Time:  O(n * r)
// Space: O(r)

// freq table, two pointers
class Solution {
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
