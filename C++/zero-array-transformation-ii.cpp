// Time:  O((n + q) * logn)
// Space: O(n)

// binary search, line sweep
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const auto& binary_search = [](auto left, auto right, const auto& check) {
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

        const auto& check = [&](int k) {
            vector<int> events(size(nums) + 1);
            for (int i = 0; i < k; ++i) {
                events[queries[i][0]] += queries[i][2];
                events[queries[i][1] + 1] -= queries[i][2];
            }
            for (int i = 0, curr = 0; i < size(nums); ++i) {
                curr += events[i];
                if (nums[i] > curr) {
                    return false;
                }
            }
            return true;
        };

        const int result = binary_search(0, static_cast<int>(size(queries)), check);
        return result <= size(queries) ? result : -1;
    }
};
