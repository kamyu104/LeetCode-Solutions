// Time:  O(mlogm)
// Space: O(1)

// sort
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(begin(score), end(score), [&](const auto& a, const auto& b) {
            return a[k] > b[k];
        });
        return score;
    }
};
