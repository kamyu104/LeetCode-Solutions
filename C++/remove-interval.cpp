// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> result;
        for (const auto& interval : intervals) {
            vector<pair<int, int>> tmp = {{interval[0], min(toBeRemoved[0], interval[1])},
                                          {max(interval[0], toBeRemoved[1]), interval[1]}};
            for (const auto& [x, y] : tmp) {
                if (x < y) {
                    result.push_back({x, y});
                }
            }
        }
        return result;
    }
};
