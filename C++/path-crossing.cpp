// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<pair<int, int>, PairHash<int>> lookup = {{0, 0}};
        int x = 0, y = 0;
        for (const auto& c : path) {
            switch(c) {
                case 'E':
                    ++x;
                    break;
                case 'W':
                    --x;
                    break;
                case 'N':
                    ++y;
                    break;
                case 'S':
                    --y;
                    break;
            }
            if (!lookup.emplace(x, y).second) {
                return true;
            }
        }
        return false;
    }

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
};
