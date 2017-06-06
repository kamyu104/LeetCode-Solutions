// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int result = 0;
        int d = numeric_limits<int>::max();
        for (const auto& nut : nuts) {
            result += (distance(nut, tree) * 2);
            d = min(d, distance(nut, squirrel) - distance(nut, tree));
        }
        return result + d;
    }

private:
    int distance(const vector<int>& a, const vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};
