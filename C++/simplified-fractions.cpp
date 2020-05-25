// Time:  O(n^2 * logn)
// Space: O(n^2)

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        unordered_set<pair<int, int>, PairHash<int>> lookup;
        for (int b = 1; b <= n; ++b) {
            for (int a = 1; a < b; ++a) {
                const auto& g = gcd(a, b);
                lookup.emplace(a / g, b / g);
            }
        }
        vector<string> result;
        transform(cbegin(lookup), cend(lookup), back_inserter(result),
                  [](const auto& kvp) {
                      return to_string(kvp.first) + "/" + to_string(kvp.second);
                  });
        return result;
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
