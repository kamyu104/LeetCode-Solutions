// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        for (const auto& q : queries) {
            const int t = q[0] % (2 * size(nums)), i = q[1];
            if (t + i < size(nums)) {
                result.emplace_back(nums[t + i]);
            } else if (i < t - static_cast<int>(size(nums))) {
                result.emplace_back(nums[i]);
            } else {
                result.emplace_back(-1);
            }
        }
        return result;
    }
};
