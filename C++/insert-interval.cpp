// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        size_t i = 0;
        vector<vector<int>> result;
        // Insert intervals appeared before newInterval.
        while (i < size(intervals) && newInterval[0] > intervals[i][1]) {
            result.emplace_back(intervals[i++]);
        }

        // Merge intervals that overlap with newInterval.
        while (i < size(intervals) && newInterval[1] >= intervals[i][0]) {
            newInterval = {min(newInterval[0], intervals[i][0]),
                           max(newInterval[1], intervals[i][1])};
            ++i;
        }
        result.emplace_back(newInterval);

        // Insert intervals appearing after newInterval.
        copy(cbegin(intervals) + i, cend(intervals), back_inserter(result));
        return result;
    }
};
