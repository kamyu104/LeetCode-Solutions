// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0;

        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> group;
            for (int j = 0; j < points.size(); ++j) {
                if (j == i) {
                    continue;
                }
                const auto dx = points[i].first - points[j].first;
                const auto dy = points[i].second - points[j].second;
                ++group[dx * dx + dy * dy];
            }
            
            for (const auto& p : group) {
                if (p.second > 1) {
                    result += p.second * (p.second - 1);
                }
            }
        }
        
        return result;
    }
};
