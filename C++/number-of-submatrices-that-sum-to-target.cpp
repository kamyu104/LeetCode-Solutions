// Time:  O(m^2*n), m is min(r, c), n is max(r, c)
// Space: O(n), which doesn't include transposed space

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if (matrix.size() > matrix[0].size()) {
            const auto& transposed = transpose(matrix);
            return numSubmatrixSumTarget(const_cast<vector<vector<int>>&>(transposed),
                                         target);
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size() - 1; ++j) {
                matrix[i][j + 1] += matrix[i][j];
            }
        }

        int result = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> prefix_sum(matrix[i].size());
            for (int j = i; j < matrix.size(); ++j) {
                unordered_map<int, int> lookup;
                ++lookup[0];
                for (int k = 0; k < matrix[i].size(); ++k) {
                    prefix_sum[k] += matrix[j][k];
                    if (lookup.count(prefix_sum[k] - target)) {
                        result += lookup[prefix_sum[k] - target];
                    }
                    ++lookup[prefix_sum[k]];
                }
            }
        }
        return result;
    }

private:
    vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
        vector<vector<int>> result(matrix[0].size(),
                                   vector<int>(matrix.size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};
