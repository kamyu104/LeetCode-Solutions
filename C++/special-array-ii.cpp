// Time:  O(n + q)
// Space: O(n)

// prefix sum
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i + 1 < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + ((nums[i + 1] & 1) != (nums[i] & 1) ? 1 : 0);
        }
        vector<bool> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            result[i] = prefix[queries[i][1]] - prefix[queries[i][0]] == queries[i][1] - queries[i][0];
        }
        return result;
    }
};
