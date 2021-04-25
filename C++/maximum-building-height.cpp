// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(begin(restrictions), end(restrictions));
        for (int i = size(restrictions) - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]));
        }
        int result = 0;
        for (int i = 1; i < size(restrictions); ++i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]));
            int left = restrictions[i - 1][0], h1 = restrictions[i - 1][1];
            int right = restrictions[i][0], h2 = restrictions[i][1];
            result = max(result, max(h1, h2) + ((right - left) - abs(h1 - h2)) / 2);
        }
        return result;
    }
};
