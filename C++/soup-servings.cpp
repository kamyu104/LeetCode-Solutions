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
    double soupServings(int N) {
        if (N > 4800) {
            return 1.0;
        }
        unordered_map<pair<int, int>, double, PairHash<int>> lookup;
        N = (N + 24) / 25;
        return dp(N, N, &lookup);
    }
    
private:
    double dp(int a, int b, unordered_map<pair<int, int>, double, PairHash<int>> *lookup) {
        if (lookup->count(make_pair(a, b))) {
            return (*lookup)[make_pair(a, b)];
        }
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (a <= 0) {
            return 1.0;
        }
        if (b <= 0) {
            return 0.0;
        }
        (*lookup)[make_pair(a, b)] = 0.25 * (dp(a - 4, b, lookup) +
                                             dp(a - 3, b - 1, lookup) +
                                             dp(a - 2, b - 2, lookup) +
                                             dp(a - 1, b - 3, lookup));
        return (*lookup)[make_pair(a, b)];
    }
};
