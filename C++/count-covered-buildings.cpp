// Time:  O(n)
// Space: O(n)

// array
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> left(n, n);
        vector<int> right(n, -1);
        vector<int> up(n, -1);
        vector<int> down(n, n);
        for (const auto& b : buildings) {
            const int x = b[0] - 1;
            const int y = b[1] - 1;
            left[y] = min(left[y], x);
            right[y] = max(right[y], x);
            up[x] = max(up[x], y);
            down[x] = min(down[x], y);
        }
        int result = 0;
        for (const auto& b : buildings) {
            const int x = b[0] - 1;
            const int y = b[1] - 1;
            if (left[y] < x && x < right[y] && down[x] < y && y < up[x]) {
                ++result;
            }
        } 
        return result;
    }
};
