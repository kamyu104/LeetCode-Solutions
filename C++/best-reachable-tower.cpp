// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int best = -1, best_x = -1, best_y = -1;
        for (const auto& t : towers) {
            const auto& x = t[0], &y = t[1], &q = t[2];
            if (!(abs(x - center[0]) + abs(y - center[1]) <= radius)) {
                continue;
            }
            if (q > best) {
                best = q;
                best_x = x;
                best_y = y;
            } else if (q == best && (x < best_x || (x == best_x && y < best_y))) {
                best_x = x;
                best_y = y;
            }
        }
        return best != -1 ? vector{best_x, best_y} : vector{-1, -1};
    }
};

// Time:  O(n)
// Space: O(1)
// array
class Solution2 {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> result(3, 1);
        for (const auto& t : towers) {
            const auto& x = t[0], &y = t[1], &q = t[2];
            if (!(abs(x - center[0]) + abs(y - center[1]) <= radius)) {
                continue;
            }
            result = min(result, {-q, x, y});
        }
        return result[0] != 1 ? vector{result[1], result[2]} : vector{-1, -1};
    }
};
