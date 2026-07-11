// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        return accumulate(cbegin(nums), cend(nums), 0, [&](const auto& accu, const auto& x) {
            return accu + (x == nums[size(nums) / 2] ? 1 : 0);
        }) == 1;
    }
};
