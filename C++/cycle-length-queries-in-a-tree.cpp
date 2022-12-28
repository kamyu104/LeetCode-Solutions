// Time:  O(q * n)
// Space: O(1)

// tree, lca
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;
        for (const auto& q : queries) {
            int x = q[0], y = q[1];
            int cnt = 1;
            while (x != y) {
                if (x > y) {
                    swap(x, y);
                }
                y /= 2;
                ++cnt;
            }
            result.emplace_back(cnt);
        }
        return result;
    }
};
