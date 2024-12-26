// Time:  O(nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int result = 0;
        sort(begin(nums), end(nums));
        int curr = numeric_limits<int>::min();
        for (const auto& x : nums) {
            if (curr > x + k) {
                continue;
            }
            curr = max(curr, x - k) + 1;
            ++result;
        }
        return result;
    }
};
