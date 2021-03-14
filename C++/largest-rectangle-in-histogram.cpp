// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> stk = {-1};
        int result = 0;
        for (int i = 0; i <= size(heights); ++i) {
            while (stk.back() != -1 && (i == size(heights) || heights[stk.back()] >= heights[i])) {
                int last = stk.back(); stk.pop_back();
                result = max(result, heights[last] * ((i - 1) - stk.back()));
            }
            stk.emplace_back(i);
        }
        return result;
    }
};
