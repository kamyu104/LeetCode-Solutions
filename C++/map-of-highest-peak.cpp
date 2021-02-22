// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        vector<pair<int, int>> q;
        for (int r = 0; r < size(isWater); ++r) {
            for (int c = 0; c < size(isWater[0]); ++c) {
                --isWater[r][c];
                if (isWater[r][c] == 0) {
                    q.emplace_back(r, c);
                }
            }
        }
        while (!empty(q)) {
            vector<pair<int, int>> new_q;
            for (const auto& [r, c] : q) {
                for (const auto& [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if (!(0 <= nr && nr < size(isWater) &&
                          0 <= nc && nc < size(isWater[0]) &&
                          isWater[nr][nc] == -1)) {
                        continue;
                    }
                    isWater[nr][nc] = isWater[r][c] + 1;
                    new_q.emplace_back(nr, nc);
                }
            }
            q = move(new_q);
        }
        return isWater;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
class Solution2 {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        vector<vector<int>> heights(size(isWater), vector<int>(size(isWater[0]), -1));
        vector<pair<int, int>> q;
        for (int r = 0; r < size(isWater); ++r) {
            for (int c = 0; c < size(isWater[0]); ++c) {
                if (isWater[r][c] == 0) {
                    continue;
                }
                heights[r][c] = 0;
                q.emplace_back(r, c);
            }
        }
        while (!empty(q)) {
            vector<pair<int, int>> new_q;
            for (const auto& [r, c] : q) {
                for (const auto& [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if (!(0 <= nr && nr < size(isWater) &&
                          0 <= nc && nc < size(isWater[0]) &&
                          heights[nr][nc] == -1)) {
                        continue;
                    }
                    heights[nr][nc] = heights[r][c] + 1;
                    new_q.emplace_back(nr, nc);
                }
            }
            q = move(new_q);
        }
        return heights;
    }
};
