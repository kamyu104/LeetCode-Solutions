// Time:  O(m)
// Space: O(m)

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        static const unordered_map<char, pair<int, int>> directions = {
            {'U', {-1, 0}}, {'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}
        };

        int x0 = startPos[0], y0 = startPos[1];
        int x = 0, y = 0;
        vector<int> result(size(s));
        iota(rbegin(result), rend(result), 1);
        unordered_map<int, vector<int>> lookup_x, lookup_y;
        lookup_x[x0 - x].emplace_back(0);
        lookup_y[y0 - y].emplace_back(0);
        for (int i = 0; i < size(s); ++i) {
            const auto& [dx, dy] = directions.at(s[i]);
            x += dx, y += dy;
            for (const auto& k : {n - x, -x - 1}) {
                if (!lookup_x.count(k)) {
                    continue;
                }
                for (const auto& j : lookup_x[k]) {
                    result[j] = min(result[j], i - j);
                }
                lookup_x.erase(k);
            }
            for (const auto& k : {n - y, -y - 1}) {
                if (!lookup_y.count(k)) {
                    continue;
                }
                for (const auto& j : lookup_y[k]) {
                    result[j] = min(result[j], i - j);
                }
                lookup_y.erase(k);
            }
            lookup_x[x0 - x].emplace_back(i + 1);
            lookup_y[y0 - y].emplace_back(i + 1);
        }
        return result;
    }
};
