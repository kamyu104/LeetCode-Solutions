// Time:  O(n + q)
// Space: O(n)

// prefix sum
class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        const auto& count = [](int64_t n) {
            return (n + 1) * n / 2;
        };
    
        vector<int> right(size(nums));
        iota(begin(right), end(right), 0);
        for (int i = size(nums) - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1]) {
                right[i] = right[i + 1];
            }
        }
        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0, curr = 0; i < size(nums); ++i) {
            if (i - 1 >= 0 && nums[i - 1] > nums[i]) {
                curr = 0;
            }
            ++curr;
            prefix[i + 1] = prefix[i] + curr;
        }
        vector<long long> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            const int l = queries[i][0];
            const int r = queries[i][1];
            const int m = min(right[l], r);
            result[i] = count(m - l + 1) + (prefix[r + 1] - prefix[m + 1]);
        }
        return result;

    }
};
