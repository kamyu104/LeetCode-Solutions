// Time:  O(m * n)
// Space: O(n)

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int result = 0;
        vector<int> heights(mat[0].size());
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                heights[j] = (mat[i][j] == 1) ? heights[j] + 1 : 0;
            }
            result += count(heights);
        }
        return result;
    }

private:
    int count(const vector<int>& heights) {
        vector<int> dp(heights.size());
        vector<int> stk;
        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[stk.back()] >= heights[i]) {
                stk.pop_back();
            }
            dp[i] = !stk.empty() ? dp[stk.back()] + heights[i] * (i - stk.back())
                                 : heights[i] * (i - (-1));
            stk.emplace_back(i);
        }
        return accumulate(cbegin(dp), cend(dp), 0);
    }
};
