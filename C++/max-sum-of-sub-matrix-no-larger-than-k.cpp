// Time:  O(min(m, n)^2 * max(m, n) * log(max(m, n)))
// Space: O(max(m, n))

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) {
            return 0;
        }

        const int m = min(matrix.size(), matrix[0].size());
        const int n = max(matrix.size(), matrix[0].size());
        int result = numeric_limits<int>::min();

        for (int i = 0; i < m; ++i) {
            vector<int> sums(n, 0);
            for (int j = i; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    sums[k] += (n == matrix.size()) ? matrix[k][j] : matrix[j][k];
                }
    
                // Find the max subarray no more than K.
                set<int> accu_sum_set;
                accu_sum_set.emplace(0);
                int accu_sum = 0;
                for (int sum : sums) {
                    accu_sum += sum;
                    auto it = accu_sum_set.lower_bound(accu_sum - k);
                    if (it != accu_sum_set.end()) {
                        result = max(result, accu_sum - *it);
                    }
                    accu_sum_set.emplace(accu_sum);
                }
            }
        }

        return result;
    }
};
