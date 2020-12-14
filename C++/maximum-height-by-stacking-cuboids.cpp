// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& cuboid : cuboids) {
            sort(begin(cuboid), end(cuboid));
        }
        cuboids.push_back({0, 0, 0});
        sort(begin(cuboids), end(cuboids));
        vector<int> dp(size(cuboids));
        for (int i = 1; i < size(cuboids); ++i) {
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][0] <= cuboids[i][0] &&
                    cuboids[j][1] <= cuboids[i][1] &&
                    cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }
        return *max_element(cbegin(dp), cend(dp));
    }
};
