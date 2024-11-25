// Time:  O(m * n)
// Space: O(n)

// mono stack
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const auto& count = [](const auto& heights) {
            int result = 0;
            vector<int> stk;
            for (int i = 0, curr = 0; i < size(heights); ++i) {
                while (!empty(stk) && heights[stk.back()] >= heights[i]) {
                    const int j = stk.back(); stk.pop_back();
                    curr -= (heights[j] - heights[i]) * (j - (!empty(stk) ? stk.back() : -1));
                }
                stk.emplace_back(i);
                curr += heights[i];
                result += curr;
            }
            return result;
        };

        int result = 0;
        vector<int> heights(size(mat[0]));
        for (int i = 0; i < size(mat); ++i) {
            for (int j = 0; j < size(mat[0]); ++j) {
                heights[j] = (mat[i][j] == 1) ? heights[j] + 1 : 0;
            }
            result += count(heights);
        }
        return result;
    }
};

// Time:  O(m * n)
// Space: O(n)
// mono stack, dp
class Solution2 {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const auto& count = [](const auto& heights) {
            vector<int> dp(size(heights));
            vector<int> stk;
            for (int i = 0; i < size(heights); ++i) {
                while (!empty(stk) && heights[stk.back()] >= heights[i]) {
                    stk.pop_back();
                }
                dp[i] = !empty(stk)
                    ? dp[stk.back()] + heights[i] * (i - stk.back())
                    : heights[i] * (i - (-1));
                stk.emplace_back(i);
            }
            return accumulate(cbegin(dp), cend(dp), 0);
        };

        int result = 0;
        vector<int> heights(size(mat[0]));
        for (int i = 0; i < size(mat); ++i) {
            for (int j = 0; j < size(mat[0]); ++j) {
                heights[j] = (mat[i][j] == 1) ? heights[j] + 1 : 0;
            }
            result += count(heights);
        }
        return result;
    }
};
