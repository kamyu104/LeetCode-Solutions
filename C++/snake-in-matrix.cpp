// Time:  O(c)
// Space: O(1)

// simulation
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        static const unordered_map<string, pair<int, int>> lookup = {
            {"UP", {-1, 0}},
            {"RIGHT", {0, 1}},
            {"DOWN", {1, 0}},
            {"LEFT", {0, -1}}
        };

        int r = 0, c = 0;
        for (const auto& x : commands) {
            const auto& [dr, dc] = lookup.at(x);
            r += dr;
            c += dc;
        }
        return r * n + c;
    }
};
