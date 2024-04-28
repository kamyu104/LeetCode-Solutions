// Time:  O(nlogn)
// Space: O(n)

// binary search, two pointers, sliding window
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        const auto& binary_search = [&](int left, int right, const auto& check) {
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        const int64_t total = (size(nums) + 1ll) * size(nums) / 2;
        return binary_search(1, size(unordered_set<int>(cbegin(nums), cend(nums))), [&](int k) {
            int64_t result = 0;
            unordered_map<int, int> cnt;
            for (int right = 0, left = 0; right < size(nums); ++right) {
                ++cnt[nums[right]];
                for (; size(cnt) == k + 1; ++left) {
                    if (--cnt[nums[left]] == 0) {
                        cnt.erase(nums[left]);
                    }
                }
                result += right - left + 1;
            }
            return result >= total - result;
        });
    }
};
