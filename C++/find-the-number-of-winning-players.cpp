// Time:  O(p), p = len(pick)
// Space: O(min(n * c, p)), c = max(y)

// freq table
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, unordered_map<int, int>> cnts;
        for (const auto& x : pick) {
            ++cnts[x[0]][x[1]];
        }
        int result = 0;
        for (const auto& [i, cnt] : cnts) {
            if (any_of(cbegin(cnt), cend(cnt), [&](const auto& x) { return i < x.second; })) {
                ++result;
            }
        }
        return result;
    }
};
