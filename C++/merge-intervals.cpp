// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<vector<int>> result;
        for (const auto& interval : intervals) {
            if (empty(result) || interval[0] > result.back()[1]) { 
                result.emplace_back(interval);
            } else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};
