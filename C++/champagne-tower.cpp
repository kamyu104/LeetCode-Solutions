// Time:  O(n^2) = O(1), since n is at most 99
// Space: O(n) = O(1)

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> result(1 + query_row);
        result[0] = poured;
        for (int i = 1; i <= query_row; ++i) {
            for(int j = i; j >= 0; --j) {
                result[j] = max((result[j] - 1), 0.0) / 2 +
                            max((result[j - 1] - 1), 0.0) / 2;
            }
        }
        return min(result[query_glass], 1.0);
    }
};
