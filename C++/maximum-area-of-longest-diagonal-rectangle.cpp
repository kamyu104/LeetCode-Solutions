// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        pair<int, int> result = {0, 0};
        for (const auto& d : dimensions) {
            result = max(result, {d[0] * d[0] + d[1] * d[1], d[0] * d[1]});
        }
        return result.second;
    }
};
