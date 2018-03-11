// Time:  O(n^2) = O(1), since n is at most 99
// Space: O(n) = O(1)

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> result(query_row + 2);
        result[0] = poured;
        for (int i = 1; i <= query_row; ++i) {
            for(int j = i; j >= 0; --j) {
                result[j] = max(0.0, (result[j] - 1) / 2);
                result[j + 1] += result[j];
            }
        }
        return min(1.0, result[query_glass]);
    }
};
