// Time:  O(n)
// Space: O(n)

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

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<pair<int, int>, int, PairHash<int>> count;
        for (const auto& domino : dominoes) {
            ++count[make_pair(*min_element(domino.cbegin(), domino.cend()),
                              *max_element(domino.cbegin(), domino.cend()))];
        }
        int result = 0;
        for (const auto& [k, v] : count) {
            result += v * (v - 1) / 2;
        }
        return result;
    }
};
