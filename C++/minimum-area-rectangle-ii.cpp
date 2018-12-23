// Time:  O(n^2) ~ O(n^3)
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
    
    double minAreaFreeRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        unordered_map<pair<double, double>, vector<pair<double, double>>, PairHash<double>> lookup;
        for (int i = 0; i < points.size() - 1; ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                lookup[make_pair(points[i][0] - points[j][0],
                                 points[i][1] - points[j][1])].emplace_back(
                                     (points[i][0] + points[j][0]) / 2,
                                     (points[i][1] + points[j][1]) / 2
                                );
                
            }
        }
        double result = numeric_limits<double>::infinity();
        for (const auto& kvp : lookup) {
            for (int i = 0; i < kvp.second.size() - 1; ++i) {
                for (int j = i + 1; j < kvp.second.size(); ++j) {
                    auto x1 = kvp.first.first;
                    auto y1 = kvp.first.second;
                    auto x2 = kvp.second[i].first - kvp.second[j].first;
                    auto y2 = kvp.second[i].second - kvp.second[j].second;
                    if (x1 * x2 + y1 * y2 == 0.0) {
                        result = min(result, sqrt((x1 * x1 + y1 * y1) *
                                                  (x2 * x2 + y2 * y2)));
                    }
                }
            }
        }
        return result != numeric_limits<double>::infinity() ? result : 0.0;
    }
};
