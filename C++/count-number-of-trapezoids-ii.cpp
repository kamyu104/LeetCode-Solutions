// Time:  O(n^2 * logr), r = max(max(abs(x), abs(y)) for x, y in points)
// Space: O(n^2)

// freq table, combinatorics
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
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<tuple<int, int>, int, TupleHash> lookup_slope;
        unordered_map<tuple<int, int, int>, int, TupleHash> lookup_line;
        unordered_map<tuple<int, int, int>, int, TupleHash> lookup_slope_length;
        unordered_map<tuple<int, int, int, int>, int, TupleHash> lookup_line_length;
        int result = 0, same = 0;
        for (int i = 0; i < size(points); ++i) {
            const int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < i; ++j) {
                const int x2 = points[j][0], y2 = points[j][1];
                const int dx = x2 - x1, dy = y2 - y1;
                const auto& g = gcd(dx, dy);
                int a = dx / g, b = dy / g;
                if (a < 0 || (a == 0 && b < 0)) {
                    a = -a, b = -b;
                }
                const int c = b * x1 - a * y1;
                result += lookup_slope[tuple(a, b)]++ - lookup_line[tuple(a, b, c)]++;
                const int l = dx * dx + dy * dy;
                same += lookup_slope_length[tuple(a, b, l)]++ - lookup_line_length[tuple(a, b, c, l)]++;
            }
        }
        return result - same / 2;
    }
};
