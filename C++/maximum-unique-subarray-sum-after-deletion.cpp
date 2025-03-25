// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int maxSum(vector<int>& nums) {
        const int mx = ranges::max(nums);
        if (mx < 0) {
            return mx;
        }
        unordered_set<int> lookup(cbegin(nums), cend(nums));
        int result = 0;
        for (const auto& x : lookup) {
            if (x > 0) {
                result += x;
            }
        }
        return result;
    }
};
