// Time:  O(n + k)
// Space: O(k)

class Solution {
private:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0},
                                                       {0, -1}, {-1, 0}};
        unordered_set<pair<int, int>, PairHash<int>> lookup;
        for (const auto& obstacle: obstacles) {
            lookup.emplace(obstacle[0], obstacle[1]);
        }
        int result = 0;
        int x = 0, y = 0, i = 0;
        for (const auto& cmd: commands) {
            if (cmd == -2) {
                i = (i - 1 + 4) % 4;
            } else if (cmd == -1) {
                i = (i + 1) % 4;
            } else {
                for (int k = 0; k < cmd; ++k) {
                    if (!lookup.count(make_pair(x + directions[i].first,
                                                y + directions[i].second))) {
                        x += directions[i].first;
                        y += directions[i].second;
                        result = max(result, x * x + y * y);
                    }
                }
            }
        }
        return result;
    }
};
