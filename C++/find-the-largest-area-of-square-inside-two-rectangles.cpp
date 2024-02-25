// Time:  O(n^2)
// Space: O(1)

// brute force, math
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int result = 0;
        for (int i = 0; i < size(bottomLeft); ++i) {
            for (int j = i + 1; j < size(bottomLeft); ++j) {
                const int max_x = max(bottomLeft[i][0], bottomLeft[j][0]);
                const int min_x = min(topRight[i][0], topRight[j][0]);
                const int max_y = max(bottomLeft[i][1], bottomLeft[j][1]);
                const int min_y = min(topRight[i][1], topRight[j][1]);
                result = max(result, min(min_x - max_x, min_y - max_y));
            }
        }
        return static_cast<long long>(result) * result;
    }
};
