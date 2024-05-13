// Time:  O(n + 26)
// Space: O(26)

// hash table
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        static const int INF = numeric_limits<int>::max();
    
        vector<int> lookup(26, INF);
        int d = INF;
        for (int i = 0; i < size(s); ++i) {
            int mn2 = max(abs(points[i][0]), abs(points[i][1]));
            if (mn2 < lookup[s[i] - 'a']) {
                swap(mn2, lookup[s[i] - 'a']);
            }
            d = min(d, mn2);
        }
        int result = 0;
        for (const auto& x : lookup) {
            if (x < d) {
                ++result;
            }
        }
        return result;
    }
};
