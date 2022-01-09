// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for (int i = 0; i < size(matrix); ++i) {
            unordered_set<int> r, c;
            for (int j = 0; j < size(matrix[0]); ++j) {
                r.emplace(matrix[i][j]);
                c.emplace(matrix[j][i]);
            }
            if (size(r) != size(matrix[0]) || size(c) != size(matrix)) {
                return false;
            }
        }
        return true;
    }
};

// Time:  O(n^2)
// Space: O(1)
// [[1,3,3,4,4],[4,1,3,3,4],[4,4,1,3,3],[3,4,4,1,3],[3,3,4,4,1]]
class Solution_Wrong {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for (int i = 0; i < size(matrix); ++i) {
            int r = 0, c = 0;
            for (int j = 0; j < size(matrix[0]); ++j) {
                r ^= matrix[i][j] ^ (j + 1);
                c ^= matrix[j][i] ^ (j + 1);
            }
            if (r || c) {
                return false;
            }
        }
        return true;
    }
};
