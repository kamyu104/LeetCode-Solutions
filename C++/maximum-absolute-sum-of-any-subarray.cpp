// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr = 0, mx = 0, mn = 0;
        for (const auto& num : nums) {
            curr += num;
            mx = max(mx, curr);
            mn = min(mn, curr);
        }
        return mx - mn;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        partial_sum(begin(nums), end(nums), begin(nums));
        return max(*max_element(cbegin(nums), cend(nums)), 0) -
               min(*min_element(cbegin(nums), cend(nums)), 0);
    }
};
