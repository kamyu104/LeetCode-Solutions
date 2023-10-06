// Time:  O(n)
// Space: O(n)

// prefix sum, hash table
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        static const int INF = numeric_limits<int>::max();

        const int64_t total = accumulate(cbegin(nums), cend(nums), 0ll);
        const int64_t q = target / total;
        target %= total;
        if (!target) {
            return q * size(nums);
        }
        int result = INF;
        unordered_map<int64_t, int> lookup = {{0, -1}};
        int64_t curr = 0;
        for (int right = 0; right < (size(nums) - 1) + (size(nums) - 1); ++right) {
            curr += nums[right % size(nums)];
            if (lookup.count(curr - target)) {
                result = min(result, right - lookup[curr - target]);
            }
            lookup[curr] = right;
        }
        return result != INF ? result + q * size(nums) : -1;
    }
};
