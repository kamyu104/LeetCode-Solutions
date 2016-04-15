// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); ++i) {
            if (lookup.count(target - nums[i])) {
                res = {lookup[target - nums[i]], i};
                break;
            }
            lookup[nums[i]] = i;
        }
        return res;
    }
};
