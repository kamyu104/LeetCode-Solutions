// Time:  O(n * m)
// Space: O(1)

// array
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> result;
        for (const auto& row : matrix) {
            result.emplace_back(accumulate(cbegin(row), cend(row), 0));
        }
        return result;
    }
};
