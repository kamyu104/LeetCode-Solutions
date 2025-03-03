// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int left = bounds[0][0], right = bounds[0][1];
        int result = right - left + 1;
        for (int i = 1; i < size(original); ++i) {
            const int diff = original[i] - original[i - 1];
            left = max(left + diff, bounds[i][0]);
            right = min(right + diff, bounds[i][1]);
            result = min(result, max(right - left + 1, 0));
        }
        return result;
    }
};
