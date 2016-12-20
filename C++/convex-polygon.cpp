// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        const auto det = [](const vector<vector<int>>& A) {
            return A[0][0]*A[1][1] - A[0][1]*A[1][0];
        };
        long n = points.size(), prev = 0, curr;
        for (int i = 0; i < n; ++i) {
            vector<vector<int>> A;
            for (int j = 1; j < 3; ++j) {
                A.push_back({points[(i + j) % n][0] - points[i][0], points[(i + j) % n][1] - points[i][1]});
            }
            if (curr = det(A)) {
                if (curr * prev < 0) {
                    return false;
                }
                prev = curr;
            }
        }
        return true;
    }
};
