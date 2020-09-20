// Time:  O(c * m * n + e), c is the number of colors
//                        , e is the number of edges in adj, at most O(c^2)
// Space: O(e)

class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        static const int MAX_COLOR = 60;

        unordered_map<int, unordered_set<int>> adj;
        for (int color = 1; color <= MAX_COLOR; ++color) {
            int min_r = size(targetGrid);
            int min_c = size(targetGrid[0]);
            int max_r = -1;
            int max_c = -1;
            for (int r = 0; r < size(targetGrid); ++r) {
                for (int c = 0; c < size(targetGrid[r]); ++c) {
                    if (targetGrid[r][c] == color) {
                        min_r = min(min_r, r);
                        min_c = min(min_c, c);
                        max_r = max(max_r, r);
                        max_c = max(max_c, c);
                    }
                } 
            }
            for (int r = min_r; r <= max_r; ++r) {
                for (int c = min_c; c <= max_c; ++c) {
                    if (targetGrid[r][c] != color) {
                        adj[color].emplace(targetGrid[r][c]);
                    }
                }
            }
        }
        unordered_map<int, int> lookup;
        for (int color = 1; color <= MAX_COLOR; ++color) {
            if (lookup.count(color)) {
                continue;
            }
            if (hasCycle(adj, color, &lookup)) {
                return false;
            }
        }
        return true;
    }

private:
    enum State {VISITING, VISITED};

    bool hasCycle(const unordered_map<int, unordered_set<int>>& adj,
                  int color,
                  unordered_map<int, int> *lookup) {
        vector<pair<int, int>> stk = {{1, color}};
        while (!empty(stk)) {
            const auto [step, color] = stk.back(); stk.pop_back();
            if (step == 1) {
                (*lookup)[color] = VISITING;
                stk.emplace_back(2, color);
                if (!adj.count(color)) {
                    continue;
                }
                for (const auto& new_color : adj.at(color)) {
                    if (lookup->count(new_color)) {
                        if ((*lookup)[new_color] == VISITED) {
                            continue;
                        }
                        return true;  // VISITING
                    }
                    stk.emplace_back(1, new_color);
                }
            } else {
                (*lookup)[color] = VISITED;
            }
        }
        return false;
    }
};
