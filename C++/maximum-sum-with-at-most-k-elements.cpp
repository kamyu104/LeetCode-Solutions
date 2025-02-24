// Time:  O(n * m)
// Space: O(1)

// greedy, quick select
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<int> candidates;
        for (int i = 0; i < size(grid); ++i) {
            int cnt = min(k, limits[i]);
            if (cnt - 1 >= 0) {
                nth_element(begin(grid[i]), begin(grid[i]) + (cnt - 1), end(grid[i]), greater<int>());
                while (cnt) {
                    candidates.emplace_back(grid[i][--cnt]);
                }
           }
        }
        int64_t result = 0;
        if (k - 1 >= 0) {
            nth_element(begin(candidates), begin(candidates) + (k - 1), end(candidates), greater<int>());
            result = accumulate(cbegin(candidates), cbegin(candidates) + k, 0ll);
        }
        return result;
    }
};
