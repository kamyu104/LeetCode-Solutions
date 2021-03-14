// Time:  O(m * n)
// Space: O(n)

// Ascending stack solution.
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int result = 0;
        vector<int> heights(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            result = max(result, largestRectangleArea(heights));
        }
        return result;
    }

private:
    int largestRectangleArea(const vector<int>& heights) {
        vector<int> stk = {-1};
        int res = 0;
        for (int i = 0; i <= size(heights); ++i) {
            while (stk.back() != -1 && (i == size(heights) || heights[stk.back()] >= heights[i])) {
                int last = stk.back(); stk.pop_back();
                res = max(res, heights[last] * ((i - 1) - stk.back()));
            }
            stk.emplace_back(i);
        }
        return res;
    }
};

// Time:  O(m * n)
// Space: O(n)
// DP solution.
class Solution2 {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }

        const int m = matrix.size();
        const int n = matrix.front().size();
        int res = 0;
        vector<int> H(n, 0);  // Height of all ones rectangle include matrix[i][j].
        vector<int> L(n, 0);  // Left closed bound of all ones rectangle include matrix[i][j].
        vector<int> R(n, n);  // Right open bound of all ones rectangle include matrix[i][j].

        for (int i = 0; i < m; ++i) {
            int left = 0, right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++H[j];  // Update height.
                    L[j] = max(L[j], left); // Update left bound.
                } else {
                    left = j + 1;
                    H[j] = L[j] = 0;
                    R[j] = n;
                }
            }

            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right);  // Update right bound.
                    res = max(res, H[j] * (R[j] - L[j]));
                } else {
                    right = j;
                }
            }
        }

        return res;
    }
};
