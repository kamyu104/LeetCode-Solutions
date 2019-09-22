// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

    int minKnightMoves(int x, int y) {
        unordered_map<pair<int, int>, int, PairHash<int>> lookup =
            {{{0, 0}, 0}, {{1, 1}, 2}, {{1, 0}, 3}};  // special cases
        return dp(x, y, &lookup);
    }

private:
    int dp(int x, int y,
           unordered_map<pair<int, int>, int, PairHash<int>> *lookup) {
        x = abs(x), y = abs(y);
        if (x < y) {
            swap(x, y);
        }
        if (!lookup->count({x, y})) {
            (*lookup)[{x, y}] = min(dp(x - 1, y - 2, lookup),
                                    dp(x - 2, y - 1, lookup)) + 1;
        }
        return (*lookup)[{x, y}];
    }
};
