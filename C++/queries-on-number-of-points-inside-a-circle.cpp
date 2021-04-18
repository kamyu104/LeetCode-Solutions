// Time:  O(q * n)
// Space: O(1)

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;
        for (const auto& q : queries) {
            result.emplace_back(0);
            for (const auto& p : points) {
                int dx = p[0] - q[0], dy = p[1] - q[1];
                if (dx * dx + dy * dy <= q[2] * q[2]) {
                    ++result.back();
                }
            }
        }
        return result;
    }
};
