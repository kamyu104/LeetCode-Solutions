// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
private:
    struct TupleHash {
        template <typename... T>
        std::size_t operator()(const std::tuple<T...>& t) const {
            return apply([](const auto&... args) {
                std::size_t seed = 0;
                ((seed ^= std::hash<std::decay_t<decltype(args)>>{}(args) + 
                        0x9e3779b9 + (seed << 6) + (seed >> 2)), ...);
                return seed;
            }, t);
        }
    };

public:
    int distinctPoints(string s, int k) {
        static const unordered_map<char, pair<int, int>> DIRECTIONS = {{'U', {0, 1}}, {'D', {0, -1}}, {'L', {-1, 0}}, {'R', {1, 0}}};

        int x = 0, y = 0;
        unordered_set<tuple<int, int>, TupleHash> lookup = {{x, y}};
        for (int i = k; i < size(s); ++i) {
            x += get<0>(DIRECTIONS.at(s[i])) - get<0>(DIRECTIONS.at(s[i - k]));
            y += get<1>(DIRECTIONS.at(s[i])) - get<1>(DIRECTIONS.at(s[i - k]));
            lookup.insert({x, y});  // emplace may be slow
        }
        return size(lookup);
    }
};
