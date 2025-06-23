// Time:  O(n)
// Space: O(n)

// math, hash table
class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        static const int POS_INF = numeric_limits<int>::max();
        static const int NEG_INF = numeric_limits<int>::min();
        int mx_x = NEG_INF;
        int mn_x = POS_INF;
        int mx_y = NEG_INF;
        int mn_y = POS_INF;
        unordered_map<int, int> lookup_mx_y;
        unordered_map<int, int> lookup_mn_y;
        unordered_map<int, int> lookup_mx_x;
        unordered_map<int, int> lookup_mn_x;
        for (const auto& c : coords) {
            const auto& x = c[0], &y = c[1];
            mx_x = max(mx_x, x);
            mn_x = min(mn_x, x);
            mx_y = max(mx_y, y);
            mn_y = min(mn_y, y);
            if (!lookup_mx_y.count(x)) {
                lookup_mx_y[x] = y;
            } else {
                lookup_mx_y[x] = max(lookup_mx_y[x], y);
            }
            if (!lookup_mn_y.count(x)) {
                lookup_mn_y[x] = y;
            } else {
                lookup_mn_y[x] = min(lookup_mn_y[x], y);
            }
            if (!lookup_mx_x.count(y)) {
                lookup_mx_x[y] = x;
            } else {
                lookup_mx_x[y] = max(lookup_mx_x[y], x);
            }
            if (!lookup_mn_x.count(y)) {
                lookup_mn_x[y] = x;
            } else {
                lookup_mn_x[y] = min(lookup_mn_x[y], x);
            }
        }
        int64_t result = 0;
        for (const auto& [x, _] : lookup_mx_y) {
            result = max(result, static_cast<int64_t>(lookup_mx_y[x] - lookup_mn_y[x]) * max(mx_x - x, x - mn_x));
        }
        for (const auto& [y, _] : lookup_mx_x) {
            result = max(result, static_cast<int64_t>(lookup_mx_x[y] - lookup_mn_x[y]) * max(mx_y - y, y - mn_y));
        }
        return result ? result : -1;
    }
};
