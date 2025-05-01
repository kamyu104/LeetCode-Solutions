// Time:  O(n + q)
// Space: O(n)

// prefix sum
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> prefix(n);
        for (int i = 0; i < n - 1; ++i) {
            prefix[i + 1] = prefix[i] + (nums[i + 1] - nums[i] <= maxDiff ? 0 : 1);
        }
        vector<bool> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            result[i] = prefix[queries[i][0]] == prefix[queries[i][1]];
        }
        return result;
    }
};
