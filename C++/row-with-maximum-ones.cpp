// Time:  O(m * n)
// Space: O(1)

// array
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> result = {-1, -1};
        for (int i = 0; i < size(mat); ++i) {
            const int curr = accumulate(cbegin(mat[i]), cend(mat[i]), 0);
            if (curr > result[1]) {
                result = {i, curr};
            }
        }
        return result;
    }
};
