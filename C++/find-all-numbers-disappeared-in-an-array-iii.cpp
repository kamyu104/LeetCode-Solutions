// Time:  O(nlogn)
// Space: O(1)

// sort
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> result;
        ranges::sort(nums);
        for (const auto& x : nums) {
            if (x < lower) {
                continue;
            }
            if (x > upper) {
                break;
            }
            if (lower <= x - 1) {
                result.push_back({lower, x - 1});
            }
            lower = x + 1;
        }
        if (lower <= upper) {
            result.push_back({lower, upper});
        }
        return result;
    }
};
