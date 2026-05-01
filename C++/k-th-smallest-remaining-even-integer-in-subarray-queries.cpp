// Time:  O(n + qlogn)
// Space: O(n)

// prefix sum, binary search
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        const auto& binary_search_right = [](int left, int right, const auto& check) {
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + (nums[i] % 2 == 0 ? 1 : 0);
        }
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            const auto& l = queries[i][0], &r = queries[i][1], &k = queries[i][2];
            const auto& j = binary_search_right(l, r, [&](int x) {
                return nums[x] / 2 < k + (prefix[x + 1] - prefix[l]);
            });
            result[i] = 2 * (k + (prefix[j + 1] - prefix[l]));
        }
        return result;
    }
};
