// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted_heights{heights};
        sort(sorted_heights.begin(), sorted_heights.end());
        int result = 0;
        for (int i = 0; i < heights.size(); ++i) {
            result += static_cast<int>(heights[i] != sorted_heights[i]);
        }
        return result;
    }
};
