// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        const auto& dim = binaryMatrix.dimensions();
        const auto& m = dim[0], &n = dim[1];
        int r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (!binaryMatrix.get(r, c)) {
                ++r;
            } else {
                --c;
            }
        }
        return (c + 1 != n) ? c + 1 : -1;
    }
};
