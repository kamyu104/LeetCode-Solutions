// Time:  O(1)
// Space: O(1)

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
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        static const vector<pair<int, int>> directions =
          {{-1, 0}, {0, 1}, {1, 0}, {0, -1},
           {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
        vector<vector<int>> result;
        unordered_set<pair<int, int>, PairHash<int>> lookup;
        for (const auto& queen : queens) {
            lookup.emplace(queen[0], queen[1]);
        }
        for (const auto& [dx, dy] : directions) {
            for (int i = 1; i <= 7; ++i) {
                int x = king[0] + dx * i;
                int y = king[1] + dy * i;
                if (lookup.count(make_pair(x, y))) {
                    result.push_back({x, y});
                    break;
                }
            }
        }
        return result;
    }
};
